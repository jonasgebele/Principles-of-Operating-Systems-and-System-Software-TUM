#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


int main(int argc, char **argv) {

    char buffer[265];

    int ssize = read(STDIN_FILENO, buffer, 265);
    ssize--;

    buffer[ssize] = 0;

    char rot13[ssize + 1];
    rot13[ssize] = 0;

    for (int i = 0; i < ssize; i++) {
        char c = buffer[i];
        if (!isalpha(c)) {
            rot13[i] = 0;
            break;
        } else {
            if ('a' <= c && c <= 'z') {
                c = toupper(buffer[i]);
            }
        }
        c = 'A' + (c - 'A' + 13) % 26;
        rot13[i] = c;
    }

    printf("Hallo: %s -- %s\n", buffer, rot13);

    return EXIT_SUCCESS;
}
