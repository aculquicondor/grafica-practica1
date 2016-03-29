#include "gizmo.h"

Gizmo::Gizmo(MvpSimpleColorProgram *program) :
        Drawable(program), program(program) {
}


const GLvoid *Gizmo::get_data() const {
    return data;
}

GLsizeiptr Gizmo::get_data_size() const {
    return 12 * sizeof(GLfloat);
}


const GLfloat Gizmo::data[] = {
    0.f, 0.f, 0.f,
    1.f, 0.f, 0.f,
    0.f, 0.f, 0.f,
    0.f, 1.f, 0.f
};


void Gizmo::draw(Camera *camera) {
    Drawable::draw(camera);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    ((MvpSimpleColorProgram *)program)->set_color(1, 0, 0);
    glDrawArrays(GL_LINES, 0, 2);

    ((MvpSimpleColorProgram *)program)->set_color(0, 1, 0);
    glDrawArrays(GL_LINES, 2, 2);
}
