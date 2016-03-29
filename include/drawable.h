#ifndef HELLO_OPENGL_DRAWABLE_H
#define HELLO_OPENGL_DRAWABLE_H

#include "GL/glew.h"
#include "camera.h"
#include "mvp_program.h"


class Drawable {
private:
    MvpProgram *program;
public:
    Drawable(MvpProgram *program);
    virtual void draw(Camera *camera);
    virtual glm::mat4 get_model();

    virtual const GLvoid *get_data() const = 0;
    virtual GLsizeiptr get_data_size() const = 0;
};


#endif //HELLO_OPENGL_DRAWABLE_H
