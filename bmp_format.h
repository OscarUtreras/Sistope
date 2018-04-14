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

//Estructura para almacenar la imagen,
typedef struct bmp
{
    char bm[2];                 //(2 Bytes) BM (Tipo de archivo)
    int tamano;                 //(4 Bytes) Tamaño del archivo en bytes
    int reservado;              //(4 Bytes) Reservado
    int offset;                 //(4 Bytes) offset, distancia en bytes entre la img y los píxeles
    int tamanoMetadatos;        //(4 Bytes) Tamaño de Metadatos (tamaño de esta estructura = 40)
    int alto;                   //(4 Bytes) Ancho (numero de píxeles horizontales)
    int ancho;                  //(4 Bytes) Alto (numero de pixeles verticales)
    short int numeroPlanos;     //(2 Bytes) Numero de planos de color
    short int profundidadColor; //(2 Bytes) Profundidad de color (debe ser 24 para nuestro caso)
    int tipoCompresion;         //(4 Bytes) Tipo de compresión (Vale 0, ya que el bmp es descomprimido)
    int tamanoEstructura;       //(4 Bytes) Tamaño de la estructura Imagen (Paleta)
    int pxmh;                   //(4 Bytes) Píxeles por metro horizontal
    int pxmv;                   //(4 Bytes) Píxeles por metro vertical
    int coloresUsados;          //(4 Bytes) Cantidad de colores usados
    int coloresImportantes;     //(4 Bytes) Cantidad de colores importantes
    int pixelesNegros;          //Cantidad de pixeles negros luego de la binarizacion
    unsigned char **pixelR;     //Puntero a los pixeles del plano R (Rojo)
    unsigned char **pixelG;     //Puntero a los pixeles del plano G (Verde)
    unsigned char **pixelB;     //Puntero a los pixeles del plano B (Azul)
    unsigned char **pixelV;     //Puntero a los pixeles del plano V
} BMP;

#endif
