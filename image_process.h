#include "bmp_format.h"

#ifndef IMAGE_PROCESS_H
#define IMAGE_PROCESS_H

unsigned char *GreyScale(bmpInfoHeader *info, unsigned char *img);
unsigned char *Binary(bmpInfoHeader *info, unsigned char *imgGrey, int umbral, int *blacks);
int nearlyBlack(bmpInfoHeader *info, int blacks, int umbClassi);

#endif
