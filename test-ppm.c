#include "ppm.h"
#include <stdlib.h>

int main()
{
  image_t *img = read_ppm("example.ppm");
  if (!img)
    return EXIT_FAILURE;
  for (size_t i = 0; i<img->width*img->height; ++i)
  {
    img->red_buffer[i] = 255-img->green_buffer[i];
  }
  write_ppm("example-out.ppm", img);
  return EXIT_SUCCESS;
}
