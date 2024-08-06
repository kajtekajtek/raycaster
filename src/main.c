// Simple raycaster
#include "../include/raycaster.h"

int main(int argc, char* argv[])
{
    const size_t img_w = 512;
    const size_t img_h = 512;
    uint32_t frame_buff[img_w * img_h];

    // game map
    const size_t map_w = 16;
    const size_t map_h = 16;
    const char map[] = "0000222222220000"\
                       "1              0"\
                       "1      11111   0"\
                       "1     0        0"\
                       "0     0  1110000"\
                       "0     3        0"\
                       "0   10000      0"\
                       "0   0   11100  0"\
                       "0   0   0      0"\
                       "0   0   1      0"\
                       "0       1      0"\
                       "0       1      0"\
                       "2       0      0"\
                       "0 0000000      0"\
                       "0              0"\
                       "0002222222200000";
    
    if (sizeof(map) != map_w * map_h + 1) {
        printf("Error: Incorrect map size. Exiting now...\n");
        exit(1);
    }

    // fill the screen with gradient
    for (size_t i = 0; i < img_h; i++) {
        for (size_t j = 0; j < img_w; j++) {
            // varies between 0 and 255 as i sweeps the vertical
            uint8_t r = 255*i/(float)img_h;
            // varies between 0 and 255 as j sweeps the horizontal
            uint8_t g = 255*j/(float)img_w;
            uint8_t b = 0;

            frame_buff[j + i * img_w] = pack_color(r, g, b, 255);
        }
    }

    // draw the map
    const size_t rect_w = img_w / map_w;
    const size_t rect_h = img_h / map_h;
    for (size_t i = 0; i < map_h; i++) {
        for (size_t j = 0; j < map_w; j++) {
            // skip empty spaces
            if (map[i * map_w + j] == ' ') continue;

            size_t rect_x = j * rect_w;
            size_t rect_y = i * rect_h;

            draw_rectangle(frame_buff, img_w, img_h, rect_x, rect_y, rect_w, 
                rect_h, pack_color(0, 255, 255, ALPHA));
        }
    }

    create_ppm_img("./out.ppm", frame_buff, img_w, img_h);

    return 0;
}
