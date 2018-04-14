#include "bmp_format.h"

#ifndef IMAGE_PROCESS_H
#define IMAGE_PROCESS_H

unsigned char *GreyScale(bmpInfoHeader *info, unsigned char *img);
unsigned char *Binary(bmpInfoHeader *info, unsigned char *imgGrey, int umbral, int *blacks);
int nearlyBlack(bmpInfoHeader *info, int blacks, int umbClassi);

void EscalaGrises(BMP* image);
void Binarizado(BMP*image, int umbBinary);
int nearlyBlack2(BMP *image, int umbCla);

#endif
