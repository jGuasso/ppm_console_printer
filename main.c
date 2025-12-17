#include "ppm_console_printer.h"
#include <stdbool.h>

bool menu(ppm_info f_info){
    printf("-------MENU-------\n");
    printf(" 1. PRINT\n");
    printf(" 2. GREYSCALE\n");
    printf(" 3. NEGATIVO\n");
    printf(" 4. NEGATIVO VERMELHO\n");
    printf(" 5. NEGATIVO VERDE\n");
    printf(" 6. NEGATIVO AZUL\n");
    printf(" 0. SAIR\n");
    int op;
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        print_ppm_file(f_info);
        printf("\nFormato:%s, Tamanho:%dx%d, Valor maximo:%d\n",f_info.format,f_info.width,f_info.height,f_info.maxval);
        break;
    case 2:
        greyScale(f_info);
        break;
    case 3:
        negative(f_info);
        break;
    case 4:
        negativeRed(f_info);
        break;
    case 5:
        negativeGreen(f_info);
        break;
    case 6:
        negativeBlue(f_info);
        break;
    case 0: 
        return false;
        break;
    default:
        break;
    }
    return true;
}

int main(){
    printf("Escreva o nome do arquivo:");
    char filename[100];
    scanf("%s",filename);
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    ppm_info f_info = carregar_imagem(file);
    fclose(file);
    while (menu(f_info));
    return 0;
}