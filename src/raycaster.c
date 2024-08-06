#include "../include/raycaster.h"

// colors are stored in four byte integers
// functions pack_color and unpack_color allow working with color channels
uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, 
                                                    const uint8_t a)
{
    return (a<<24) + (b<<16) + (g<<8) + r;
}

void unpack_color(uint32_t *color, uint8_t *r, uint8_t *g, uint8_t *b,
                                                        uint8_t *a)
{
    *r = (*color >> 0) & 255;
    *g = (*color >> 8) & 255;
    *b = (*color >> 16) & 255;
    *a = (*color >> 24) & 255;
}

// create .ppm image from a one dimensional pixel array
void create_ppm_img(char *filename, uint32_t *img, size_t w, size_t h)
{
    FILE* file_ptr;

    // opening the file in binary write mode
    file_ptr = fopen(filename, "wb");

    if (file_ptr == NULL) {
        printf("Error: the image was not created. Exiting now...\n");
        exit(1);
    }

    fputs("P6\n", file_ptr);

    char str[STR_SIZE];
    sprintf(str, "%d ", w);

    fputs(str, file_ptr);

    memset(str, 0, STR_SIZE);
    sprintf(str, "%d\n", h);

    fputs(str, file_ptr);

    fputs("255\n", file_ptr);

    for (size_t i = 0; i < h * w; i++) {
        uint8_t r, g, b, a;
        
        unpack_color(&img[i], &r, &g, &b, &a);

        fputc(r, file_ptr);
        fputc(g, file_ptr);
        fputc(b, file_ptr);
    }

    fclose(file_ptr);

    printf("Image saved to %s.\n", filename);
}

void draw_rectangle(uint32_t *img, size_t img_w, size_t img_h, size_t x, 
                        size_t y, size_t w, size_t h, uint32_t color)
{
    for (size_t i = 0; i < w; i++) {
        for (size_t j = 0; j < h; j++) {
            size_t cx = x + i;
            size_t cy = y + j;

            if (cx >= img_w && cy >= img_h) {
                printf("Error: draw_rectangle(). Exiting now...\n");
                exit(1);
            }

            img[cx + cy * img_w] = color;
        }
    }
}
