# PPM Console Printer

Este projeto é uma ferramenta desenvolvida em C para carregar, processar e visualizar imagens no formato **PPM (Portable Pixmap)** diretamente no terminal, utilizando sequências de escape ANSI para a representação de cores.

## 🚀 Funcionalidades

* **Leitura de Arquivos**: Suporte para os formatos **P3** (ASCII) e **P6** (Binário).
* **Visualização no Console**: Renderização da imagem no terminal através de cores de fundo RGB.
* **Processamento de Imagem**:
    * **Filtro GreyScale**: Converte a imagem para tons de cinza.
    * **Negativo Total**: Inverte todas as cores da imagem.
    * **Negativo Seletivo**: Inverte apenas os canais de cor individuais (Vermelho, Verde ou Azul).
* **Exportação**: Permite salvar a imagem processada em novos arquivos `.ppm` nos formatos P3 ou P6.

## 🛠️ Como Compilar

Para compilar o projeto, utilize um compilador de C (como o GCC) integrando todos os módulos:

gcc main.c ppm_console_printer.c ansi_colors.c -o ppm_printer

## 📂 Estrutura do Projeto

* **main.c**: Contém o ponto de entrada do programa e a interface do menu interativo.
* **ppm_console_printer.c / .h**: Implementa a lógica de carregamento, alocação de memória dinâmica para a matriz de pixels, filtros e escrita de arquivos.
* **ansi_colors.c / .h**: Biblioteca auxiliar para converter valores RGB em códigos ANSI compatíveis com o terminal.

## 📖 Modo de Uso

1. Execute o programa: `./ppm_printer`.
2. Digite o nome ou caminho do arquivo `.ppm` (ex: `imagem.ppm`).
3. Utilize o menu para navegar entre as opções:
    * **1. PRINT**: Visualiza a imagem no console.
    * **2. SALVAR**: Exporta as alterações para um novo arquivo.
    * **3. GREYSCALE**: Aplica o filtro de tons de cinza.
    * **4-7. NEGATIVOS**: Aplica inversões de cor totais ou por canal.

## ⚠️ Requisitos e Recomendações

* **Terminal**: É necessário um terminal com suporte a **True Color (24-bit RGB)**.
* **Zoom**: Recomenda-se retirar o zoom do terminal para uma melhor visualização.
* **Memória**: O programa utiliza alocação dinâmica (`malloc`) para a matriz de pixels. Imagens muito grandes podem exigir muita RAM.
