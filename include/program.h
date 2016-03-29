#ifndef HELLO_OPENGL_PROGRAM_H
#define HELLO_OPENGL_PROGRAM_H

#include <map>

#include <glm/glm.hpp>

#include "load_shader.h"


class Program {
private:
    GLuint program_id;
    std::map<std::string, GLint> uniforms;

    GLint set_uniform(const std::string &name);
public:
    Program(const char *vertex_shader, const char *fragment_shader);
    virtual void load() const;

    void set_uniform(const std::string &name, glm::vec3 value);
    void set_uniform(const std::string &name, glm::vec4 value);
    void set_uniform(const std::string &name, glm::mat4 value);
};

#endif //HELLO_OPENGL_PROGRAM_H
