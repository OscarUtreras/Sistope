#include "handler.h"

void Handler()
{
  bmpInfoHeader info;
  bmpFileHeader header;
  unsigned char *img;
  unsigned char *imgGrey;
  unsigned char *imgBinary;
  int umbral=90;

  // Primera fase del pipeline: Leer la imagen
  img=LoadBMP("porsche.bmp", &header, &info);
  //imgBinary=(unsigned char*)malloc(info.imgsize); // Solicitamos memoria para la binarizada

  // Segunda fase del pipeline: Imagena escala de grises
  imgGrey=GreyScale(&info, img);

  // Tercera fase del pipeline: Escala de grises a imagen binarizada
  imgBinary=Binary(&info, imgGrey, umbral);

  // Cuarta fase del pipeline: Almacenar imagen binarizada
  SaveBMP("out.bmp", &header, &info, imgBinary);

  // Quinta frase del pipeline: Mostrar resultados de nearly black

  free(img);
  free(imgGrey);
  free(imgBinary);
}
