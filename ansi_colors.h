#ifndef ANSI_COLORS_H
#define ANSI_COLORS_H
//biblioteca criada para facilitar a utilização do ccódigo ANSI para colorir o terminal
//João Antônio Guerim Guasso
// baseado em https://gist.github.com/JBlond/2fea43a3049b38287e5e9cefc87b2124

#ifdef __cplusplus
extern "C" {
#endif

// Cores de texto
#define TEXT_BLACK "\033[30m"
#define TEXT_RED "\033[31m"
#define TEXT_GREEN "\033[32m"
#define TEXT_YELLOW "\033[33m"
#define TEXT_BLUE "\033[34m"
#define TEXT_PURPLE "\033[35m"
#define TEXT_CYAN "\033[36m"
#define TEXT_WHITE "\033[37m"
/*high intensity*/
#define TEXT_H_BLACK "\033[90m"
#define TEXT_H_RED "\033[91m"
#define TEXT_H_GREEN "\033[92m"
#define TEXT_H_YELLOW "\033[93m"
#define TEXT_H_BLUE "\033[94m"
#define TEXT_H_PURPLE "\033[95m"
#define TEXT_H_CYAN "\033[96m"
#define TEXT_H_WHITE "\033[97m"

/*#Não mudou no meu
//fontes
#define PRIMARY_FONT "\033[10m"
#define ALTERNATIVE_FONT_1 "\033[11m"
#define ALTERNATIVE_FONT_2 "\033[12m"
#define ALTERNATIVE_FONT_3 "\033[13m"
#define ALTERNATIVE_FONT_4 "\033[14m"
#define ALTERNATIVE_FONT_5 "\033[15m"
#define ALTERNATIVE_FONT_6 "\033[16m"
#define ALTERNATIVE_FONT_7 "\033[17m"
#define ALTERNATIVE_FONT_8 "\033[18m"
#define ALTERNATIVE_FONT_9 "\033[19m"
*/

// Cores de fundo
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_PURPLE "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"
/*high intensity*/
#define BG_H_BLACK "\033[100m"
#define BG_H_RED "\033[101m"
#define BG_H_GREEN "\033[102m"
#define BG_H_YELLOW "\033[103m"
#define BG_H_BLUE "\033[104m"
#define BG_H_PURPLE "\033[105m"
#define BG_H_CYAN "\033[106m"
#define BG_H_WHITE "\033[107m"

// Efeitos
#define TEXT_BOLD "\033[1m"
#define TEXT_FAINT "\033[2m"
#define TEXT_ITALIC "\033[3m"
#define TEXT_UNDERLINE "\033[4m"
#define TEXT_BLINK "\033[5m"
#define TEXT_BLINK_RAPID "\033[6m" //por enquanto ele piscou na mesma velocidade
#define TEXT_REVERSE "\033[7m"
#define TEXT_HIDE "\033[8m"
#define TEXT_CROSSEDOUT "\033[9m"

//funcoes para cores RGB
char* bg_color(int r, int g, int b);
char* text_color(int r, int g, int b);

// Macro para evitar quebra de linha
#define AVOID_LINE_BREAK "\033[999C"

// Reset
#define RESET_CONSOLE "\033[0m"

#ifdef __cplusplus
}
#endif

#endif // ANSI_COLORS_H