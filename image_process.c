#include "image_process.h"

/* Funcion encargada de pasar la imagen a escala de grises.
Entrada: Estructura con la informacion de la imagen y arreglo con los pixeles de la imagen.
Salida: imagen en escala de grises (arreglo con los pixeles de la imagen). */
unsigned char *GreyScale(bmpInfoHeader *info, unsigned char *img)
{
  int x, y, b, g, r, grey, cantBits = 4;
  unsigned char *imgGrey = (unsigned char *)malloc(info->imgsize);
  for (y = 0; y < info->height; y++)
  {
    for (x = 0; x < info->width; x++)
    {
      b = (img[cantBits * (x + y * info->width)+1] * 0.11);
      g = (img[cantBits * (x + y * info->width)+2] * 0.59);
      r = (img[cantBits * (x + y * info->width)+3] * 0.3);
      grey = r + g + b;
      imgGrey[cantBits * (x + y * info->width)] = img[cantBits * (x + y * info->width)];
      imgGrey[cantBits * (x + y * info->width)+1] = grey;
      imgGrey[cantBits * (x + y * info->width)+2] = grey;
      imgGrey[cantBits * (x + y * info->width)+3] = grey;
    }
  }
  return imgGrey;
}

void EscalaGrises(BMP* image)
{
  int R,G,B,grey,i,j;
  for (i = image->alto - 1; i >= 0; i--)
    {
      for (j = 0; j < image->ancho; j++)
      {
        B=image->pixelB[i][j] * 0.11;
        G=image->pixelG[i][j] * 0.59;
        R=image->pixelR[i][j] * 0.3;
        grey=B+G+R;
        image->pixelB[i][j]=grey;
        image->pixelG[i][j]=grey;
        image->pixelR[i][j]=grey;
      }
    }
}

/* Funcion encargada de binarizar la imagen.
Entrada: Estructura con la informacion de la imagen, imagen en escala de grises, umbral de binarizacion y cantidad de pixeles negros.
Salida: imagen binarizada (arreglo con los pixeles de la imagen), cantidad de pixeles negros por referencia. */
unsigned char *Binary(bmpInfoHeader *info, unsigned char *imgGrey, int umbral, int *blacks)
{
  int x, y, cantBits = 4;
  *blacks=0;
  unsigned char *imgBinary = (unsigned char *)malloc(info->imgsize);
  for (y = 0; y < info->height; y++)
  {
    for (x = 0; x < info->width; x++)
    {
      if ((imgGrey[cantBits * (x + y * info->width)+1]) > umbral)
      {
        imgBinary[cantBits * (x + y * info->width)]=imgGrey[cantBits * (x + y * info->width)];
        imgBinary[cantBits * (x + y * info->width)+1]=255;
        imgBinary[cantBits * (x + y * info->width)+2]=255;
        imgBinary[cantBits * (x + y * info->width)+3]=255;
      }
      else
        *blacks=*blacks+1;
    }
  }
  return imgBinary;
}

void Binarizado(BMP*image, int umbBinary)
{
  int i,j,contador=0;
  for (i = image->alto - 1; i >= 0; i--)
  {
    for (j = 0; j < image->ancho; j++)
    {
      if (image->pixelB[i][j] > umbBinary)
      {
        image->pixelB[i][j] = 255;
        image->pixelG[i][j] = 255;
        image->pixelR[i][j] = 255;
      }
      else
      {
        image->pixelB[i][j] = 0;
        image->pixelG[i][j] = 0;
        image->pixelR[i][j] = 0;
        contador++;
      }
    }
  }
  image->pixelesNegros = contador;
}

/* Funcion encargada clasificar la imagen binarizada.
Entrada: Estructura con la informacion de la imagen, cantidad de pixeles negros y umbral de clasificacion.
Salida: 1 si es nearly black o 0 si no es nearly black. */

int nearlyBlack(bmpInfoHeader *info, int blacks, int umbClassi)
{
  float average;
  average = ((float)blacks)/(info->width * info->height)*100;
  if (average < umbClassi)
    return 0;
  return 1;
}


int nearlyBlack2(BMP *image, int umbCla)
{
    float result = ((float)image->pixelesNegros / ((float)image->alto * (float)image->ancho)) * 100;
    if (result > umbCla)
        return 1;
    return 0;
}
