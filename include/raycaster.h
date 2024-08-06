// Main header file
#include "include.h"

// colors are stored in four byte integers
// functions pack_color and unpack_color allow working with color channels
uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, 
                                                    const uint8_t a);

void unpack_color(uint32_t *color, uint8_t *r, uint8_t *g, uint8_t *b, 
                                                        uint8_t *a);

// create .ppm image from a one dimensional pixel array
void create_ppm_img(char *filename, uint32_t *img, size_t w, size_t h);

void draw_rectangle(uint32_t *img, size_t img_w, size_t img_h, size_t x, 
                        size_t y, size_t w, size_t h, uint32_t color);

