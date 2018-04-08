#include "image_process.h"

/* Funcion encargada de pasar la imagen a escala de grises.
Entrada: Estructura con la informacion de la imagen y arreglo con los pixeles de la imagen.
Salida: imagen en escala de grises (arreglo con los pixeles de la imagen). */
unsigned char *GreyScale(bmpInfoHeader *info, unsigned char *img)
{
  int x, y, b, g, r, grey, cantBits = 3;
  unsigned char *imgGrey = (unsigned char *)malloc(info->imgsize);
  for (y = 0; y < info->height; y++)
  {
    for (x = 0; x < info->width; x++)
    {
      b = (img[cantBits * (x + y * info->width)] * 0.11);
      g = (img[cantBits * (x + y * info->width) + 1] * 0.59);
      r = (img[cantBits * (x + y * info->width) + 2] * 0.3);
      grey = r + g + b;
      imgGrey[cantBits * (x + y * info->width)] = grey;
      imgGrey[cantBits * (x + y * info->width) + 1] = grey;
      imgGrey[cantBits * (x + y * info->width) + 2] = grey;
    }
  }
  return imgGrey;
}

/* Funcion encargada de binarizar la imagen.
Entrada: Estructura con la informacion de la imagen, imagen en escala de grises, umbral de binarizacion y cantidad de pixeles negros.
Salida: imagen binarizada (arreglo con los pixeles de la imagen), cantidad de pixeles negros por referencia. */
unsigned char *Binary(bmpInfoHeader *info, unsigned char *imgGrey, int umbral, int *blacks)
{
  int x, y, cantBits = 3;
  *blacks=0;
  unsigned char *imgBinary = (unsigned char *)malloc(info->imgsize);
  for (y = 0; y < info->height; y++)
  {
    for (x = 0; x < info->width; x++)
    {
      if ((imgGrey[cantBits * (x + y * info->width)]) > umbral)
      {
        imgBinary[cantBits * (x + y * info->width)] = 255;
        imgBinary[cantBits * (x + y * info->width) + 1] = 255;
        imgBinary[cantBits * (x + y * info->width) + 2] = 255;
      }
      else
        *blacks=*blacks+1;
    }
  }
  return imgBinary;
}

/* Funcion encargada clasificar la imagen binarizada.
Entrada: Estructura con la informacion de la imagen, imagen binarizada y umbral de clasificacion.
Salida: 1 si es nearly black o 0 si no es nearly black. */
int nearlyBlack(bmpInfoHeader *info, int blacks, int umbClassi)
{
  float average;
  average = ((float)blacks)/(info->width * info->height)*100;
  if (average < umbClassi)
    return 0;
  return 1;
}
