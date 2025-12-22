#include "ppm.hpp"
#include "ansi_colors.h"
#include <iostream>

ppm::ppm(std::ifstream& file)
{
    file.clear(); 
    file.seekg(0, std::ios::beg);

    /*Cabeçalho*/
    //Formato
    if (!(file >> this->format)) return;
    // Width x Height
    if (!(file >> this->width)) return;
    if (!(file >> this->height)) return;
    //Maxval
    if (!(file >> this->maxval)) return;
    //Aloca grid
    this->grid = std::vector<std::vector<pixel>>(height,std::vector<pixel>(width));
    
    //Pula espaço em branco
    file.ignore();

    //P3
    if(this->format[1]=='3')
    {
        for (int y = 0; y < this->height; y++)
        {
            for (int x = 0; x < this->width; x++)
            {
                file >> this->grid[y][x].r >> this->grid[y][x].g >> this->grid[y][x].b;
            }
        }
    //P6
    }else if(this->format[1]=='6'){
        for (int y = 0; y < this->height; y++)
        {
            file.read(reinterpret_cast<char*>(this->grid[y].data()), this->width * sizeof(pixel));
        }
    }   
}

ppm::~ppm()
{
}

void ppm::printImage(){
    for (int y = 0; y < this->height; y++)
    {
        for (int x = 0; x < this->width; x++)
        {
            std::cout << bg_color((int)this->grid[y][x].r,(int)this->grid[y][x].g,(int)this->grid[y][x].b) << "  ";
        }
        std::cout << RESET_CONSOLE << "\n";
    }
}

void ppm::greyScale(){
    unsigned char grey;
    for (int y = 0; y < this->height; y++)
    {
        for (int x = 0; x < this->width; x++)
        {
            grey = (this->grid[y][x].r + this->grid[y][x].g + this->grid[y][x].b)/3;
            this->grid[y][x].r=grey;
            this->grid[y][x].g=grey;
            this->grid[y][x].b=grey;
        }
        
    }   
}

void ppm::negativeRed(){
    for (int y = 0; y < this->height; y++)
    {
        for (int x = 0; x < this->width; x++)
        {
            this->grid[y][x].r = this->maxval - this->grid[y][x].r;
        }
    }
}

void ppm::negativeGreen(){
    for (int y = 0; y < this->height; y++)
    {
        for (int x = 0; x < this->width; x++)
        {
            this->grid[y][x].g = this->maxval - this->grid[y][x].g;
        }
    }
}

void ppm::negativeBlue(){
    for (int y = 0; y < this->height; y++)
    {
        for (int x = 0; x < this->width; x++)
        {
            this->grid[y][x].b = this->maxval - this->grid[y][x].b;
        }
    }
}

void ppm::negative(){
    for (int y = 0; y < this->height; y++)
    {
        for (int x = 0; x < this->width; x++)
        {
            this->grid[y][x].r = this->maxval - this->grid[y][x].r;
            this->grid[y][x].g = this->maxval - this->grid[y][x].g;
            this->grid[y][x].b = this->maxval - this->grid[y][x].b;
        }
    }
}

void ppm::saveFile(std::string filename){
    std::cout << "Nao feito ainda" << std::endl;
}