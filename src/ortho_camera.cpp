#include "ortho_camera.h"

OrthoCamera::OrthoCamera(int width, int height, float zoom) {
    float h_margin = width * zoom / 2, v_margin = height * zoom / 2;
    vp = glm::ortho(-h_margin, h_margin, -v_margin, v_margin);
}


glm::mat4 OrthoCamera::get_vp() const {
    return vp;
}