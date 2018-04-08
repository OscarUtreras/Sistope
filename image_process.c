#include "image_process.h"

unsigned char *GreyScale(bmpInfoHeader *info, unsigned char *img)
{
  int x,y,b,g,r,grey,cantBits=3;
  unsigned char *imgGrey=(unsigned char*)malloc(info->imgsize);
  for (y=0; y<info->height; y++)
  {
    for (x=0; x<info->width; x++)
    {
      b=(img[cantBits*(x+y*info->width)]*0.11);
      g=(img[cantBits*(x+y*info->width)+1]*0.59);
      r=(img[cantBits*(x+y*info->width)+2]*0.3);
      grey = r+g+b;
      imgGrey[cantBits*(x+y*info->width)]=grey;
      imgGrey[cantBits*(x+y*info->width)+1]=grey;
      imgGrey[cantBits*(x+y*info->width)+2]=grey;
    }
  }
  return imgGrey;
}

unsigned char *Binary(bmpInfoHeader *info, unsigned char *imgGrey, int umbral)
{
  int x,y,cantBits=3;
  unsigned char *imgBinary=(unsigned char*)malloc(info->imgsize);
  for (y=0; y<info->height; y++)
  {
    for (x=0; x<info->width; x++)
    {
      if((imgGrey[cantBits*(x+y*info->width)]) > umbral)
      {
        imgBinary[cantBits*(x+y*info->width)]=255;
        imgBinary[cantBits*(x+y*info->width)+1]=255;
        imgBinary[cantBits*(x+y*info->width)+2]=255;
      }
    }
  }
  return imgBinary;
}

int nearlyBlack(bmpInfoHeader *info, unsigned char *imgBinary, int umbClassi)
{
  int x,y,cantBits=3;
  float cont=0, average;
  for (y=0; y<info->height; y++)
  {
    for (x=0; x<info->width; x++)
    {
      if((imgBinary[cantBits*(x+y*info->width)])==0)
      {
        cont++;
      }
    }
  }
  average=cont/(info->width*info->height)*100;
  if(average<umbClassi)
    return 0;
  return 1;
}
