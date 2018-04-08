#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef BMP_FORMAT_H
#define BMP_FORMAT_H

/*Estructura encargada de almacenar la información del Header de la imagen BMP*/
typedef struct bmpFileHeader
{
  // 2 bytes de identificación
  uint32_t size;   //Tamaño del archivo
  uint16_t resv1;  // Reservado
  uint16_t resv2;  // Reservado
  uint32_t offset; // Offset hasta hasta los datos de imagen
} bmpFileHeader;

/*Estructura encargada de almacenar la información de la imagen BMP*/
typedef struct bmpInfoHeader
{
  uint32_t headersize; // Tamaño de la cabecera
  uint32_t width;      // Ancho
  uint32_t height;     // Alto
  uint16_t planes;     // Planos de color (Siempre 1)
  uint16_t bpp;        // Bits por pixel
  uint32_t compress;   // Compresión
  uint32_t imgsize;    // Tamaño de los datos de imagen
  uint32_t bpmx;       // Resolución X en bits por metro
  uint32_t bpmy;       // Resolución Y en bits por metro
  uint32_t colors;     // Colors used en la paleta
  uint32_t imxtcolors; // Colores importantes. 0 si son todos
} bmpInfoHeader;
#endif
