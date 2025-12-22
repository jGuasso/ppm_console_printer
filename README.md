# PPM Console Printer (C++ Version)

Este projeto é uma ferramenta desenvolvida em C++ para carregar, processar e visualizar imagens no formato **PPM (Portable Pixmap)** diretamente no terminal, utilizando sequências de escape ANSI para representação de cores True Color.

## 🚀 Funcionalidades

* **Leitura de Arquivos**: Suporte para formatos **P3** (ASCII) e **P6** (Binário) utilizando `std::ifstream`.
* **Visualização no Console**: Renderização da imagem no terminal através de cores de fundo RGB via códigos ANSI.
* **Processamento de Imagem (OO)**:
    * **Filtro GreyScale**: Converte a imagem para tons de cinza.
    * **Negativo Total**: Inverte todas as cores da imagem.
    * **Negativos Seletivos**: Inversão individual de canais (R, G ou B).
* **Exportação**: Salva imagens processadas em novos arquivos `.ppm` (P3 ou P6).

## 🛠️ Tecnologias Utilizadas

* **C++11/17**: Core do sistema e manipulação de arquivos.
* **STL (Standard Template Library)**: Uso de `std::vector` para gerenciamento automático de memória da matriz de pixels.
* **Integração C/C++**: Módulos de cores ANSI mantidos em C para performance e compatibilidade.

## 📂 Estrutura do Projeto

* **main.cpp**: Interface de menu interativo e ponto de entrada.
* **ppm.cpp / ppm.hpp**: Classe `ppm` que encapsula a lógica de I/O e processamento de imagem.
* **ansi_colors.c / ansi_colors.h**: Biblioteca em C para manipulação de cores no terminal.

## ⚙️ Como Compilar e Rodar

O projeto utiliza um **Makefile** para gerenciar a compilação híbrida (C e C++).

1.  Certifique-se de ter o `make`, `gcc` e `g++` instalados.
2.  No terminal, execute:
    ```bash
    make
    ```
3.  Execute o programa:
    ```bash
    ./ppm_printer
    ```

## ⚠️ Requisitos

* **Terminal**: Suporte a **True Color (24-bit RGB)**.
* **Memória**: Utiliza `std::vector<std::vector<pixel>>` para alocação dinâmica segura.