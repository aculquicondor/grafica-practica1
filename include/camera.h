#ifndef HELLO_OPENGL_CAMERA_H
#define HELLO_OPENGL_CAMERA_H

#include <glm/glm.hpp>


class Camera {
public:
    virtual glm::mat4 get_vp() const = 0;
};

#endif //HELLO_OPENGL_CAMERA_H
