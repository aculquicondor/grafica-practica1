#ifndef HELLO_OPENGL_GIZMO_H
#define HELLO_OPENGL_GIZMO_H

#include "drawable.h"
#include "mvp_simple_color_program.h"


class Gizmo : public Drawable {
private:
    static const GLfloat data[];
    MvpProgram *program;

public:
    Gizmo(MvpSimpleColorProgram *program);
    const GLvoid *get_data() const;
    GLsizeiptr get_data_size() const;
    void draw(Camera *camera);
};

#endif //HELLO_OPENGL_GIZMO_H
