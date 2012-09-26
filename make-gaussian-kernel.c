#include "ppm.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
  image_t *img = alloc_image(33, 33);
  if (!img)
    return EXIT_FAILURE;
  double w = img->width;
  double h = img->height;
  int sum = 0;
  for (size_t j = 0; j<img->height; ++j)
    for (size_t i = 0; i<img->width; ++i)
    {
      double x = 4*(i-0.5*w)/w;
      double y = 4*(j-0.5*h)/h;
      x += y;
      double val = 255*exp(-x*x-y*y);
      img->red_buffer[i+img->width*j] = val;
      img->green_buffer[i+img->width*j] = val;
      img->blue_buffer[i+img->width*j] = val;
      sum += (int) val;
    }
  printf("kernel sum: %d\n", sum);
  write_ppm("gaussian-kernel.ppm", img);
  return EXIT_SUCCESS;
}
