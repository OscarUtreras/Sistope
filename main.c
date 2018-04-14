#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "handler.h"

int main(int argc, char **argv)
{
  Handler(argc, argv);
  /*
  BMP *img=abrirImagen("imagen_1.bmp");
  EscalaGrises(img);
  Binarizado(img,50);
  guardarImagen(img, "out_1.bmp");
  if(nearlyBlack2(img, 90)==1)
    printf("Yes\n");
  else
    printf("No\n");

  BMP *img=abrirImagen("imagen_2.bmp");
  EscalaGrises(img);
  Binarizado(img,50);
  guardarImagen(img, "out_1.bmp");
  if(nearlyBlack2(img, 90)==1)
    printf("Yes\n");
  else
    printf("No\n");
  */

  return 0;
}
