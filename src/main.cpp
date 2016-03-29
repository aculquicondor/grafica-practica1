#include <iostream>
#include <cmath>

#include "scene.h"
#include "ortho_camera.h"
#include "gizmo.h"

using namespace std;


MvpSimpleColorProgram *program = nullptr;


class Square : public Drawable {
private:
    glm::vec3 data[4];
public:
    Square(GLfloat xc, GLfloat yc, GLfloat side) : Drawable(::program) {
        data[0] = glm::vec3(xc + side / 2, yc + side / 2, 0);
        data[1] = glm::vec3(xc - side / 2, yc + side / 2, 0);
        data[2] = glm::vec3(xc - side / 2, yc - side / 2, 0);
        data[3] = glm::vec3(xc + side / 2, yc - side / 2, 0);
    }

    void draw(Camera *camera) {
        Drawable::draw(camera);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glDrawArrays(GL_LINE_LOOP, 0, 4);
    }

    const GLvoid *get_data() const {
        return data;
    }

    GLsizeiptr get_data_size() const {
        return 12 * sizeof(GLfloat);
    }
};


class Circle : public Drawable {
private:
    glm::vec3 data[100];
    static constexpr double pi = 4 * atan(1.);
public:
    Circle(GLfloat xc, GLfloat yc, GLfloat radius) : Drawable(::program) {
        for (int i = 0; i < 100; ++i) {
            data[i] = glm::vec3(GLfloat(xc + radius * sin(i * pi / 50)),
                                GLfloat(yc + radius * cos(i * pi / 50)),
                                0);
        }
    }
    void draw(Camera *camera) {
        Drawable::draw(camera);

        ::program->set_color(.4f, .6f, 1.f);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glDrawArrays(GL_LINE_LOOP, 0, 100);
    }

    const GLvoid *get_data() const {
        return data;
    }

    GLsizeiptr get_data_size() const {
        return 300 * sizeof(GLfloat);
    }
};


Scene *scene = nullptr;


void question_1(float xc, float yc, float side) {
    scene->add(new Square(xc, yc, side));
}


void question_2(float xc, float yc, float radius) {
    scene->add(new Circle(xc, yc, radius));
}


void question_3(float radius, float reduction, int circles) {
    float xc = 0;
    for (int i = 0; i < circles; ++i) {
        scene->add(new Circle(xc, 0, radius));
        radius *= reduction;
        xc -= radius / 4;
    }
}


void question_4(float radius, float reduction, int circles) {
    float xc = 0;
    for (int i = 0; i < circles; ++i) {
        scene->add(new Circle(xc, 0, radius));
        xc += radius;
        radius *= reduction;
        xc += radius;
    }
}

void question_5(float radius, float reduction, int circles, float angle) {
    float xc = 0, yc = 0, _sin = sin(angle), _cos = cos(angle);
    for (int i = 0; i < circles; ++i) {
        scene->add(new Circle(xc, yc, radius));
        xc += radius * (1 + reduction) * _cos;
        yc += radius * (1 + reduction) * _sin;
        radius *= reduction;
    }
}

int main() {
    scene = new Scene(800, 600, new OrthoCamera(800, 600, .1));
    program = new MvpSimpleColorProgram;
    Drawable *gizmo = new Gizmo(program);
    scene->add(gizmo);

    //question_1(5, 2, 10);
    //question_2(5, 2, 10);
    //question_3(20, .8, 5);
    //question_4(6, .8, 5);
    question_5(6, .8, 5, .7);
    scene->run();

    delete gizmo;
    delete scene;
    delete program;
    return 0;
}