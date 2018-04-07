#include "bmp_format.h"

#ifndef IMAGE_PROCESS_H
#define IMAGE_PROCESS_H

float imageProcess(bmpInfoHeader *info, unsigned char *img, unsigned char *imgb, int umbral);
unsigned char *GreyScale(bmpInfoHeader *info, unsigned char *img);
unsigned char *Binary(bmpInfoHeader *info, unsigned char *imgGrey, int umbral);

#endif
