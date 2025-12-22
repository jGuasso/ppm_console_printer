#include "ppm.hpp"
#include <iostream>

bool menu(ppm& img){
    std::cout << "\n";
    std::cout <<" 1. PRINT\n";
    std::cout <<" 2. SALVAR\n";
    std::cout <<" 3. GREYSCALE\n";
    std::cout <<" 4. NEGATIVO\n";
    std::cout <<" 5. NEGATIVO VERMELHO\n";
    std::cout <<" 6. NEGATIVO VERDE\n";
    std::cout <<" 7. NEGATIVO AZUL\n";
    std::cout <<" 0. SAIR\n";
    int op;
    std::cin >> op;

    switch(op)
    {
    case 1:
        img.printImage();
        break;
    case 2: {
        std::string filename;
        std::cin >> filename;
        img.saveFile(filename);
        break;
    }
    case 3:
        img.greyScale();
        break;
    case 4:
        img.negative();
        break;
    case 5:
        img.negativeRed();
        break;
    case 6:
        img.negativeGreen();
        break;
    case 7:
        img.negativeBlue();
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
    std::cout << "Escreva o nome do arquivo: ";
    std::string filename;
    std::cin >> filename;
    std::ifstream file(filename);
    ppm img(file);
    std::cout << "\nFormato:" << img.getFormat();
    std::cout << " Tamanho:" << img.getHeight() << "x" << img.getWidth();
    std::cout << " Valor Maximo:" << img.getMaxval() << std::endl;
    file.close();
    while (menu(img));
    
    return 0;
}