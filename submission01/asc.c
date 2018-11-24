#include <stdio.h>

#define CHAR_MIN 0
#define CHAR_MAX 127

void printHeader(void);
void printRow(int i);
void printOctal(int i);
void printDecimal(int i);
void printHeximal(int i);
void printChar(int i);
void printNewLine();
void tabulator();

int main(int argc, char** argv) {

    printHeader();

    for(int i = CHAR_MIN; i <= CHAR_MAX; i++){
        printRow(i);
    }

    return 0;
}

void printHeader(void){
    printf("Oct\tDec\tHex\tChar\n");
}
void printRow(int i){
    printOctal(i);
    tabulator();
    printDecimal(i);
    tabulator();
    printHeximal(i);
    tabulator();
    printChar(i);
    printNewLine();
}

void printOctal(int i){
    printf("%03o", i);
}
void printDecimal(int i){
    printf("%u", i);
}
void printHeximal(int i){
    printf("%02x", i);
}
void printChar(int i){
    printf("%c", i);
}
void printNewLine(){
    printf("\n");
}
void tabulator(){
    printf("\t");
}
