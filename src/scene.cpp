#include "scene.h"


Scene::Scene(int width, int height, Camera *camera) : camera(camera) {
    if (!glfwInit()) {
        std::cerr << "ERROR: could not start GLFW3\n";
        exit(1);
    }

    window = glfwCreateWindow(width, height, "Hello Triangle", NULL, NULL);
    if (!window) {
        std::cerr << "ERROR: could not open window with GLFW3\n";
        glfwTerminate();
        exit(2);
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        exit(3);
    }

    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    std::cerr << "Renderer: " << renderer << std::endl;
    std::cerr << "OpenGL version supported " << version << std::endl;

    glGenVertexArrays(1, &vertex_array_id);
    glBindVertexArray(vertex_array_id);

    if (buffer_ids.capacity() > 0) {
        buffer_ids.resize(buffer_ids.capacity());
        glGenBuffers(int(buffer_ids.capacity()), buffer_ids.data());
    }
}


Scene::~Scene() {
    glfwTerminate();
}


void Scene::run() {
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do {
        draw();
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);
}

void Scene::add(Drawable *drawable) {
    if (drawables.size() == buffer_ids.size()) {
        std::size_t prev_capacity = buffer_ids.size();
        buffer_ids.push_back(0);
        buffer_ids.resize(buffer_ids.capacity());
        glGenBuffers(int(buffer_ids.capacity() - prev_capacity),
                     &buffer_ids[prev_capacity]);
    }
    glBindBuffer(GL_ARRAY_BUFFER, buffer_ids[drawables.size()]);
    glBufferData(GL_ARRAY_BUFFER, drawable->get_data_size(), drawable->get_data(), GL_STATIC_DRAW);
    drawables.push_back(drawable);
}

void Scene::draw() {
    glfwSwapBuffers(window);
    glEnableVertexAttribArray(0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (std::size_t i = 0; i < drawables.size(); ++i) {
        glBindBuffer(GL_ARRAY_BUFFER, buffer_ids[i]);
        drawables[i]->draw(camera);
    }

    glDisableVertexAttribArray(0);
}
