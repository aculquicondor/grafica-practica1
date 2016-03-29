#include "drawable.h"


Drawable::Drawable(MvpProgram *program) : program(program) { }

void Drawable::draw(Camera *camera) {
    program->load();
    glm::mat4 mvp = camera != nullptr ? camera->get_vp() * get_model() : get_model();
    program->set_mvp(mvp);
}


glm::mat4 Drawable::get_model() {
    return glm::mat4(1.0f);
}
