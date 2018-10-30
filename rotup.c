#include <stdio.h>
#include <unistd.h>
#include<string.h>

#define STDIN 0

int main(int argc, char** argv) {

    // Einlesen
    char buf[256];
    int laenge = read(STDIN, buf, 256);

    // Zeilenumbruch abschneiden
    char neu[laenge-3];
    for(int i = 0; i < laenge-1; i++){
        neu[i] = buf[i];
    }
    printf("Hallo: %s -- ", neu);

    // Kleinbuchstaben in Großbuchstaben umwandeln
    for(int i = 0; i < strlen(neu); i++){
        if(97 <= neu[i] && neu[i] <= 122){
            neu[i] = neu[i] - 32;
        }
    }

    // Abschneiden
    int grenze = 0;
    for(int i = 0; i < laenge-1; i++){
        grenze++;
        if(neu[i]<65 || neu[i] > 122 || (neu[i] > 90 && neu[i] < 97)) {
            grenze--;
            break;
        }
    }

    // Rotation durchführen
    char result[grenze];
    for(int i = 0; i < grenze; i++){
        result[i] = (neu[i]+13)%91;
        if(result[i]<65){
            result[i] = result[i] + 65;
        }
        printf("%c", result[i]);
    }

    return 0;
}
