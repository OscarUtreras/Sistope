#include "image_process.h"

float imageProcess(bmpInfoHeader *info, unsigned char *img, unsigned char *imgb, int umbral)
{
  int x, y;
  int b, g, r;
  int gris;
  float cont = 0;
  float average;
  for (y = info->height; y > 0; y-=1)
  {
    for(x = 0; x < info->width; x+=1)
    {
      b=(img[3*(x+y*info->width)]*0.11);
      g=(img[3*(x+y*info->width)+1]*0.59);
      r=(img[3*(x+y*info->width)+2]*0.3);
      gris = r+g+b;

      /*
      imgb[3*(x+y*info->width)]=gris;
      imgb[3*(x+y*info->width)+1]=gris;
      imgb[3*(x+y*info->width)+2]=gris;
      */

      if(gris > umbral)
      {
        cont += 1;
        /*
        imgb[3*(x+y*info->width)]=gris;
        imgb[3*(x+y*info->width)+1]=gris;
        imgb[3*(x+y*info->width)+2]=gris;
        */

      }
    }
  }
  average = cont/(info->width*info->height);
  return average;
}

unsigned char *GreyScale(bmpInfoHeader *info, unsigned char *img)
{
  int x,y,b,g,r,grey;
  unsigned char *imgGrey=(unsigned char*)malloc(info->imgsize);
  for (y=0; y<info->height; y++)
  {
    for (x=0; x<info->width; x++)
    {
      b=(img[3*(x+y*info->width)]*0.11);
      g=(img[3*(x+y*info->width)+1]*0.59);
      r=(img[3*(x+y*info->width)+2]*0.3);
      grey = r+g+b;
      imgGrey[3*(x+y*info->width)]=grey;
      imgGrey[3*(x+y*info->width)+1]=grey;
      imgGrey[3*(x+y*info->width)+2]=grey;
    }
  }
  return imgGrey;
}

unsigned char *Binary(bmpInfoHeader *info, unsigned char *imgGrey, int umbral)
{
  int x,y,grey;
  unsigned char *imgBinary=(unsigned char*)malloc(info->imgsize);
  for (y=0; y<info->height; y++)
  {
    for (x=0; x<info->width; x++)
    {
      grey=(imgGrey[3*(x+y*info->width)]);
      if(grey > umbral)
      {
        imgBinary[3*(x+y*info->width)]=255;
        imgBinary[3*(x+y*info->width)+1]=255;
        imgBinary[3*(x+y*info->width)+2]=255;
      }
    }
  }
  return imgBinary;
}
