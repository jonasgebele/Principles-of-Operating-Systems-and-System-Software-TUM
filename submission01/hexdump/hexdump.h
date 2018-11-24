const int BYTES_PER_ROW = 16;

void hexdump(FILE *output, char *buffer, int length);
int calculateRowNumber(int length);
void printOffset(int rowNumber);
void printLeerzeichen(int anzahl);
void printDoppelpunkt();
void printNewLine();
void printText(char buffer[], int start);
void printASCII(char buffer[], int start);

void hexdump(FILE *output, char *buffer, int length) {
    buffer[length] = 0;
    for (int i = 0; i < calculateRowNumber(length); i++) {
        printOffset(i);
        printLeerzeichen(1);
        printDoppelpunkt();
        printLeerzeichen(1);
        printASCII(buffer, i);
        printLeerzeichen(2);
        printText(buffer, i);
        printNewLine();
    }
}

int calculateRowNumber(int length){
    return ceil(((double) length) / ((double) BYTES_PER_ROW));
}

void printOffset(int rowNumber) {
    printf("%06x", rowNumber*BYTES_PER_ROW);
}

void printASCII(char buffer[], int start) {
    for(int i = start * BYTES_PER_ROW; i < BYTES_PER_ROW + start * BYTES_PER_ROW; i++){

        if(buffer[i] == 0) {
            printf("00");
            for(int j = 0; j < i%BYTES_PER_ROW; i++){
                printf("  ");
            }
            return;
        }

        printf("%02x", buffer[i]);
        printLeerzeichen(1);
    }
}

void printText(char buffer[], int start) {
    for(int i = start * BYTES_PER_ROW; i < BYTES_PER_ROW + start * BYTES_PER_ROW; i++){

        if(buffer[i] == 0) {
            return;
        }

        if(!(isalpha(buffer[i]) || buffer[i] == 32)){
            printf(".");
        }
        else {
            printf("%c", buffer[i]);
        }
    }
}

void printLeerzeichen(int anzahl) {
    for (int i = 0; i < anzahl; i++) {
        printf(" ");
    }
}

void printDoppelpunkt() {
    printf(":");
}

void printNewLine() {
    printf("\n");
}
