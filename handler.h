#include "io_image.h"
#include "image_process.h"

#include <ctype.h>

#ifndef HANDLER_H
#define HANDLER_H

int getArguments(int argc, char **argv, int *n_images, int *umbBinary, int *umbClassi, int *flag);
void pipeline(int image_n, int umbral, int flag, int umbClassi);
void Handler(int argc, char **argv);

#endif
