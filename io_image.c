#include "io_image.h"

/* Funcion encargada cargar la imagen BMP.
Entrada: nombre de la imagen, estructura que almacenara el header de la imagen y estructura que almacenara la informacion de la imagen.
Salida: imagen cargada (arreglo con los pixeles de la imagen) y por referencia el header e informacion de la imagen. */
unsigned char *LoadBMP(char *filename, bmpFileHeader *header, bmpInfoHeader *bInfoHeader)
{
  FILE *f;
  unsigned char *imgdata; // Datos de imagen
  uint16_t type;          // 2 bytes identificativos

  f = fopen(filename, "r");
  if (!f)
    return NULL; // Si no podemos leer, no hay imagen

  // Leemos los dos primeros bytes
  fread(&type, sizeof(uint16_t), 1, f);
  if (type != 0x4D42) // Comprobamos el formato (Mapa de bits de Windows)
  {
    fclose(f);
    return NULL;
  }
  // Leemos la cabecera de fichero completa
  fread(header, sizeof(bmpFileHeader), 1, f);

  // Leemos la cabecera de información completa
  fread(bInfoHeader, sizeof(bmpInfoHeader), 1, f);

  /* Reservamos memoria para la imagen, ¿cuánta?
     Tanto como indique imgsize */
  imgdata = (unsigned char *)malloc(bInfoHeader->imgsize);

  /* Nos situamos en el sitio donde empiezan los datos de imagen,
   nos lo indica el offset de la cabecera de fichero*/
  fseek(f, header->offset, SEEK_SET);

  // Leemos los datos de imagen, tantos bytes como imgsize
  fread(imgdata, bInfoHeader->imgsize, 1, f);

  // Cerramos
  fclose(f);
  // Devolvemos la imagen
  return imgdata;
}

/* Procedimiento encargada almacenar la imagen BMP binarizada.
Entrada: nombre de la imagen, estructura con el header de la imagen, estructura con la informacion de la imagen y imagen binarizada (arreglo con los pixeles de la imagen.
Salida: genera un archivo BMP con la imagen binarizada. */
void SaveBMP(char *filename, bmpInfoHeader *bInfoHeader, unsigned char *imgdata)
{
  bmpFileHeader header;
  FILE *f;
  uint16_t type = 0x4D42; //Seteamos el tipo de fichero

  header.size = bInfoHeader->imgsize + sizeof(bmpFileHeader) + sizeof(bmpInfoHeader);
  /* header.resv1=0; */
  /* header.resv2=1; */
  /* El offset será el tamaño de las dos cabeceras + 2 (información de fichero)*/
  header.offset = sizeof(bmpFileHeader) + sizeof(bmpInfoHeader) + 2;
  remove(filename);
  f = fopen(filename, "w+");
  if (!f)
    printf("No se abrio el archivo\n"); //En caso de que no se pueda abrir el fichero
  else
  {
    fwrite(&type, sizeof(uint16_t), 1, f);            //Introducimos el tipo
    fwrite(&header, sizeof(bmpFileHeader), 1, f);     //Guardamos el header
    fwrite(bInfoHeader, sizeof(bmpInfoHeader), 1, f); //Pasamos los parámetros al archivo
    fwrite(imgdata, bInfoHeader->imgsize, 1, f);      //Almacenamos la imagen
    fclose(f);                                        //Cerramos el archivo
  }
}

/* Procedimiento encargado de mostrar la informacion de la imagen cargada.
Entrada: estructura con la informacion de la imagen.
Salida: por pantalla se muestra la informacionde la imagen. */
void DisplayInfo(bmpInfoHeader *info)
{
  printf("Tamaño de la cabecera: %u\n", info->headersize);
  printf("Anchura: %d\n", info->width);
  printf("Altura: %d\n", info->height);
  printf("Planos (1): %d\n", info->planes);
  printf("Bits por pixel: %d\n", info->bpp);
  printf("Compresión: %d\n", info->compress);
  printf("Tamaño de datos de imagen: %u\n", info->imgsize);
  printf("Resolucón horizontal: %u\n", info->bpmx);
  printf("Resolucón vertical: %u\n", info->bpmy);
  printf("Colores en paleta: %d\n", info->colors);
  printf("Colores importantes: %d\n", info->imxtcolors);
}
