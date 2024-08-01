// Simple raycaster
#include "../include/raycaster.h"

int main(int argc, char* argv[])
{
    const size_t img_w = 512;
    const size_t img_h = 512;
    uint32_t frame_buff[img_w * img_h];

    for (size_t i = 0; i < img_h; i++) {
        for (size_t j = 0; j < img_w; j++) {
            uint8_t r = 255*i/(float)img_h;
            uint8_t g = 255*j/(float)img_w;
            uint8_t b = 0;

            frame_buff[j + i * img_w] = pack_color(r, g, b, 255);
        }
    }

    create_ppm_img("./out.ppm", frame_buff, img_w, img_h);

    return 0;
}
