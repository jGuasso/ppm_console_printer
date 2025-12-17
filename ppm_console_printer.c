#include "ansi_colors.h"
#include "ppm_console_printer.h"

void _carregar_p3_(FILE*file, ppm_info f_info){
    for (int y = 0; y < f_info.height; y++) {
        for (int x = 0; x < f_info.width; x++) {
            fscanf(file,"%d %d %d",&f_info.grid[y][x].r, &f_info.grid[y][x].g, &f_info.grid[y][x].b);
        }
    }
    return;
}

void _carregar_p6_(FILE*file, ppm_info f_info){
    for (int i = 0; i < f_info.height; i++)
    {
        for (int j = 0; j < f_info.width; j++)
        {
            fread(&f_info.grid[i][j].r, sizeof(unsigned char), 1, file);
            fread(&f_info.grid[i][j].g, sizeof(unsigned char), 1, file);
            fread(&f_info.grid[i][j].b, sizeof(unsigned char), 1, file);
        }
    }
    return;
}

void print_ppm_file(ppm_info f_info){
    for (int i = 0; i < f_info.height; i++)
    {
        for (int j = 0; j < f_info.width; j++)
        {
            printf("%s  ",bg_color(f_info.grid[i][j].r, f_info.grid[i][j].g, f_info.grid[i][j].b));
        }
        printf(RESET"\n");
    }
    return;
}

ppm_info carregar_imagem(FILE* file){
    rewind(file);
    ppm_info f_info;
    
    // Inicializa o ponteiro como NULL para segurança
    f_info.grid = NULL;

    if (fscanf(file, "%s", f_info.format) != 1) return f_info;
    fscanf(file, "%d %d", &f_info.width, &f_info.height);
    fscanf(file, "%d", &f_info.maxval);
    fgetc(file); // Pula o whitespace após o maxval

    // Alocação da matriz
    f_info.grid = (pixel**)malloc(sizeof(pixel*) * f_info.height);
    if (f_info.grid == NULL) {
        printf("Erro ao alocar linhas.\n");
        return f_info; 
    }
    for (int i = 0; i < f_info.height; i++) {
        f_info.grid[i] = (pixel*)malloc(sizeof(pixel) * f_info.width);
        if (f_info.grid[i] == NULL) {
            printf("Erro ao alocar colunas.\n");
            return f_info;
        }
    }

    switch (f_info.format[1]) {
        case '3':
            _carregar_p3_(file, f_info);
            break;
        case '6':
            _carregar_p6_(file, f_info);
            break;
        default:
            printf("Formato de arquivo invalido!\n");
            break;
    }

    return f_info; // FALTAVA ISSO
}