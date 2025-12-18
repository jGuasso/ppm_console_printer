#ifndef PPM_CONSOLE_PRINTER_H
#define PPM_CONSOLE_PRINTER_H

#include <stdio.h>
#include <stdlib.h>

//biblioteca criada para PRINTAR arquivos .ppm no terminal
//João Antônio Guerim Guasso

typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}pixel;

typedef struct
{
    char format[3];
    int width;
    int height;
    int maxval;
    pixel** grid;
}ppm_info;

ppm_info carregar_imagem(FILE* file);
void print_ppm_file(ppm_info f_info);
void greyScale(ppm_info f_info);
void negativeRed(ppm_info f_info);
void negativeGreen(ppm_info f_info);
void negativeBlue(ppm_info f_info);
void negative(ppm_info f_info);
void salvar_ppm_file(ppm_info f_info, char filename[100]);

#endif //PPM_CONSOLE_PRINTER_H