#include "bmp_format.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#ifndef IO_IMAGE_H
#define IO_IMAGE_H

unsigned char *LoadBMP(char *filename, bmpFileHeader *header, bmpInfoHeader *bInfoHeader);
void SaveBMP(char *filename, bmpInfoHeader *bInfoHeader, unsigned char *imgdata);
void DisplayInfo(bmpInfoHeader *info);

BMP *abrirImagen(char *filename);
void guardarImagen(BMP *imagen, char *filename);

#endif
