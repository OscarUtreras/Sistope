#include "bmp_format.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#ifndef READ_IMAGE_H
#define READ_IMAGE_H

unsigned char *LoadBMP(char *filename, bmpFileHeader *header, bmpInfoHeader *bInfoHeader);
void SaveBMP(char *filename, bmpFileHeader *header,bmpInfoHeader *bInfoHeader,unsigned char *imgdata);
void DisplayInfo(bmpInfoHeader *info);

#endif
