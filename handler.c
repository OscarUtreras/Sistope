#include "handler.h"
#include <stdio.h>
#include <unistd.h>

/* Función que obtiene los valores de cada parametro ingresado.
Entrada: argc, argv, cantidad de imagenes, umbral de bonarizacion, umbral de clasificacion y bandera (indica si se muestra informacion por pantalla).
Salida: cantidad de imagenes, umbral de bonarizacion, umbral de clasificacion y bandera por referencia. */
int getArguments(int argc, char **argv, int *n_images, int *umbBinary, int *umbClassi, int *flag)
{
    int argument;
    while ((argument = getopt(argc, argv, "c:u:n:b")) != -1)
    {
        switch (argument)
        {
        case 'c':
            if(strcmp(optarg,"-u") == 0)
            {
              printf("Tiene que ingresar la cantidad de imagenes luego de -c.\n");
              return 1;
            }
            sscanf(optarg, "%d", n_images);
            break;
        case 'u':
            if(strcmp(optarg,"-n") == 0)
            {
              printf("Tiene que ingresar el umbral para binarizar la imagen luego de -u.\n");
              return 1;
            }
            sscanf(optarg, "%d", umbBinary);
            break;
        case 'n':
            if(strcmp(optarg,"-b") == 0)
            {
              printf("Tiene que ingresar el umbral para la clasificacion luego de -n.\n");
              return 1;
            }
            sscanf(optarg, "%d", umbClassi);
            break;
        case 'b':
            *flag = 1;
            break;
        case '?':
            if (optopt == 'c' || optopt == 'u' || optopt == 'n')
                fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
            else if (isprint(optopt))
                fprintf(stderr, "Opcion desconocida '%c'\n", optopt);
            else
                fprintf(stderr, "Opcion con caracter desconocido `\\x%x'.\n", optopt);
            return 1;
        default:
            exit(1);
        }
    }
    return 0;
}

/* Funcion encargada de invocar a las distintas funciones necesarias para obtener la imagen binarizada .
Entrada: cantidad de imagenes, umbral de bonarizacion, umbral de clasificacion y bandera (indica si se muestra informacion por pantalla).
Salida: nada. */
int pipeline(int image_n, int umbral, int flag, int umbClassi)
{
    bmpInfoHeader info;
    bmpFileHeader header;
    unsigned char *img;
    unsigned char *imgGrey;
    unsigned char *imgBinary;
    char *filename = (char *)malloc(sizeof(char) * 16);
    int result, blacks;

    // Primera fase del pipeline: Leer la imagen
    sprintf(filename, "imagen_%d.bmp", image_n);
    img = LoadBMP(filename, &header, &info);
    if(img==NULL)
      return 1;

    // Segunda fase del pipeline: Pasar imagen a escala de grises
    imgGrey = GreyScale(&info, img);

    // Tercera fase del pipeline: Psar de escala de grises a imagen binarizada
    imgBinary = Binary(&info, imgGrey, umbral, &blacks);

    // Cuarta frase del pipeline: Mostrar resultados de nearly black (en caso de que se solicite a traves de la bandera)
    if (flag == 1)
    {
        result = nearlyBlack(&info, blacks, umbClassi);
        if (result == 1)
            printf("| %s   |      yes         | \n", filename);
        else
            printf("| %s   |       no         | \n", filename);
    }

    // Quinta fase del pipeline: Almacenar imagen binarizada
    sprintf(filename, "out_%d.bmp", image_n);
    SaveBMP(filename, &info, imgBinary);

    free(img);
    free(imgGrey);
    free(imgBinary);
    return 0;
}

/* Procedimiento encargado de manejar la ejecución del programa.
Entrada: argc y argv.
Salida: nada. */
void Handler(int argc, char **argv)
{
    int i, n_images=-1, umbBinary=-1, umbClassi=-1, flag=-1;
    int test = getArguments(argc, argv, &n_images, &umbBinary, &umbClassi, &flag);
    if(argc<7)
        printf("Faltan argumentos, por favor ejecute el programa con los argumentos necesarios.\n");
    else
    {
      if (test == 0)
      {
        if (flag == 1)
          printf("|    Image       |   nearly black?  |\n");
        for (i = 1; i <= n_images; i++)
        {
          if(pipeline(i, umbBinary, flag, umbClassi)==1)
            printf("No se encontro la imagen_%d.bmp.\n", i);
        }
      }
    }
}
