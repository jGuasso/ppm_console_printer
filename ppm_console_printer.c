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
    for (int y = 0; y < f_info.height; y++)
    {
        fread(f_info.grid[y], sizeof(pixel), f_info.width, file);
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

    return f_info;
}

void greyScale(ppm_info f_info){
    unsigned char cinza;
    pixel *p;
    for (int i = 0; i < f_info.height; i++)
    {
        for (int j = 0; j < f_info.width; j++)
        {
            p = &f_info.grid[i][j];
            cinza = (p->r + p->g + p->b)/3;
            p->r=cinza;
            p->g=cinza;
            p->b=cinza;
        }
    }
    
}

void negativeRed(ppm_info f_info){
    for (int i = 0; i < f_info.height; i++)
    {
        for (int j = 0; j < f_info.width; j++)
        {
            f_info.grid[i][j].r = f_info.maxval - f_info.grid[i][j].r;
        }
    }
}

void negativeGreen(ppm_info f_info){
    for (int i = 0; i < f_info.height; i++)
    {
        for (int j = 0; j < f_info.width; j++)
        {
            f_info.grid[i][j].g = f_info.maxval - f_info.grid[i][j].g;
        }
    }
}

void negativeBlue(ppm_info f_info){
    for (int i = 0; i < f_info.height; i++)
    {
        for (int j = 0; j < f_info.width; j++)
        {
            f_info.grid[i][j].b = f_info.maxval - f_info.grid[i][j].b;
        }
    }
}

void negative(ppm_info f_info){
    for (int i = 0; i < f_info.height; i++)
    {
        for (int j = 0; j < f_info.width; j++)
        {
            f_info.grid[i][j].r = f_info.maxval - f_info.grid[i][j].r;
            f_info.grid[i][j].g = f_info.maxval - f_info.grid[i][j].g;
            f_info.grid[i][j].b = f_info.maxval - f_info.grid[i][j].b;
        }
    }
}

void print_ppm_file(ppm_info f_info){
    for (int i = 0; i < f_info.height; i++)
    {
        for (int j = 0; j < f_info.width; j++)
        {
            printf("%s  ",bg_color(f_info.grid[i][j].r, f_info.grid[i][j].g, f_info.grid[i][j].b));
        }
        printf(RESET_CONSOLE"\n");
    }
    return;
}

void _salvar_p3_(ppm_info f_info, FILE* file){
    pixel *p;
    for (int y = 0; y < f_info.height; y++)
    {
        for (int x = 0; x < f_info.width; x++)
        {
            p = &f_info.grid[y][x];
            fprintf(file,"%d %d %d",p->r,p->g,p->b);
            if (x<f_info.width-1)
            {
                fprintf(file," ");
            }
        }
        if (y<f_info.height-1)
        {
            fprintf(file,"\n");
        }
    }
}

void _salvar_p6_(ppm_info f_info, FILE* file){
    for (int y = 0; y < f_info.height; y++)
    {
        fwrite(f_info.grid[y], sizeof(pixel), f_info.width, file);
    }
}

void salvar_ppm_file(ppm_info f_info, char filename[100]){
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(file,"%s\n",f_info.format);
    fprintf(file,"%d %d\n",f_info.width,f_info.height);
    fprintf(file,"%d\n",f_info.maxval);
    switch (f_info.format[1])
    {
    case '3':
        _salvar_p3_(f_info,file);
        break;
    case '6':
        _salvar_p6_(f_info,file);
        break;
    default:
        break;
    }
    fclose(file);
}