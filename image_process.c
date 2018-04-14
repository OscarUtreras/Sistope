#include "image_process.h"

/* Funcion encargada de pasar la imagen a escala de grises.
Entrada: Estructura con la informacion de la imagen y arreglo con los pixeles de la imagen.
Salida: imagen en escala de grises (arreglo con los pixeles de la imagen). */
void GreyScale(BMP* image)
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

void Binary(BMP*image, int umbBinary)
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

int nearlyBlack(BMP *image, int umbCla)
{
    float result = ((float)image->pixelesNegros / ((float)image->alto * (float)image->ancho)) * 100;
    if (result > umbCla)
        return 1;
    return 0;
}
