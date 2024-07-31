#include "raycaster.h"

// colors are stored in four byte integers
// functions pack_color and unpack_color allow working with color channels
uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255)
{
    return (a<<24) + (b<<16) + g(<<8) + r;
}

void unpack_color(uint32_t *color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a)
{
    *r = (*color >> 0) & 255;
    *g = (*color >> 8) & 255;
    *b = (*color >> 16) & 255;
    *a = (*color >> 24) & 255;
}

// create .ppm image from a one dimensional pixel array
void create_ppm_img(char *filename, char *img[], uint32_t *img_size, size_t w, size_t h)
{
    assert(*img_size == w*h);

    FILE* file_ptr;

    // opening the file in binary write mode
    file_ptr = fopen(filename, "wb");

    if (file_ptr == NULL) {
        printf("Error: the image was not created. Exiting now.");
        exit(1);
    }

    fputs("P6\n%d %d\n255", file_ptr);

    for (size_t i = 0; i < h * w; i++) {
        uint8_t r, g, b, a;
        
        unpack_color(image[i], r, g, b, a);

        fputc(r, file_ptr);
    }

    fclose(file_ptr);
}
