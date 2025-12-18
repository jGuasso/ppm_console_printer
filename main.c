#include "ppm_console_printer.h"
#include <stdbool.h>

bool menu(ppm_info f_info){
    printf("\n");
    printf(" 1. PRINT\n");
    printf(" 2. SALVAR\n");
    printf(" 3. GREYSCALE\n");
    printf(" 4. NEGATIVO\n");
    printf(" 5. NEGATIVO VERMELHO\n");
    printf(" 6. NEGATIVO VERDE\n");
    printf(" 7. NEGATIVO AZUL\n");
    printf(" 0. SAIR\n");
    int op;
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        print_ppm_file(f_info);
        break;
    case 2:
        char filename[100];
        printf("Nome do arquivo:\n");
        scanf("%s",filename);
        salvar_ppm_file(f_info,filename);
    case 3:
        greyScale(f_info);
        break;
    case 4:
        negative(f_info);
        break;
    case 5:
        negativeRed(f_info);
        break;
    case 6:
        negativeGreen(f_info);
        break;
    case 7:
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
    printf("\nFormato:%s, Tamanho:%dx%d, Valor maximo:%d\n",f_info.format,f_info.width,f_info.height,f_info.maxval);
    fclose(file);
    while (menu(f_info));
    return 0;
}