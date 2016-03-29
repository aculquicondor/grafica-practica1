#ifndef HELLO_OPENGL_LOAD_SHADER_H
#define HELLO_OPENGL_LOAD_SHADER_H

#include <iostream>
#include <fstream>
#include <vector>

#include <GL/glew.h>

GLuint load_shaders(const char *vertex_file_path, const char *fragment_file_path);

#endif //HELLO_OPENGL_LOAD_SHADER_H
