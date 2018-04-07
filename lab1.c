#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
#include "read_image.h"
#include "image_process.h"
*/

#include "handler.h"
//int argc, char **argv
int main()
{
  /*
  bmpInfoHeader info;
  bmpFileHeader header;
  unsigned char *img;
  unsigned char *imgb;
  int umbral=90;

  img=LoadBMP("porsche.bmp", &header, &info);
  imgb=(unsigned char*)malloc(info.imgsize);
  float average = imageProcess(&info, img, imgb, umbral);
  printf("average: %.6f\n", average);
  SaveBMP("out.bmp", &header, &info, imgb);
  */

  Handler();


  /* Getopt
  int c;
  int bFlag = 0;
  int amount_pictures = -1;
  int threshold_binary = -1;
  int threshold_classification = -1;
  while((c = getopt (argc, argv, "c:u:n:b")) != -1)
  {
    switch(c)
    {
      case 'c':
        sscanf(optarg, "%d", &amount_pictures);
        break;
      case 'u':
        sscanf(optarg, "%d", &threshold_binary);
        break;
      case 'n':
        sscanf(optarg, "%d", &threshold_classification);
        break;
      case 'b':
        bFlag = 1;
        break;
      case '?':

        return 1;
      default:
        abort();
    }
  }
  */
  return 0;
}
