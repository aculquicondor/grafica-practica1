#ifndef HELLO_OPENGL_GLFW_APPLICATION_H
#define HELLO_OPENGL_GLFW_APPLICATION_H

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "drawable.h"
#include "camera.h"

class Scene {
private:
    GLuint vertex_array_id;
    GLFWwindow *window;
    std::vector<GLuint> buffer_ids;
    std::vector<Drawable *> drawables;
    Camera* camera;

    void draw();

public:
    Scene(int width=800, int height=600, Camera *camera=nullptr);
    virtual ~Scene();
    void run();
    void add(Drawable *drawable);
};

#endif //HELLO_OPENGL_GLFW_APPLICATION_H
