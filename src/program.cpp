#include "program.h"


Program::Program(const char *vertex_shader, const char *fragment_shader) :
    program_id(load_shaders(vertex_shader, fragment_shader)) {
}


void Program::load() const {
    glUseProgram(program_id);
}


GLint Program::set_uniform(const std::string &name) {
    if (uniforms.find(name) == uniforms.end())
        return uniforms[name] = glGetUniformLocation(program_id, name.c_str());
    else
        return uniforms[name];
}


void Program::set_uniform(const std::string &name, glm::vec3 value) {
    glUniform3fv(set_uniform(name), 1, &value[0]);
}


void Program::set_uniform(const std::string &name, glm::vec4 value) {
    glUniform4fv(set_uniform(name), 1, &value[0]);
}


void Program::set_uniform(const std::string &name, glm::mat4 value) {
    glUniformMatrix4fv(set_uniform(name), 1, GL_FALSE, &value[0][0]);
}
