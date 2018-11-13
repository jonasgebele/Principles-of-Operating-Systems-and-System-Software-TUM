#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hexdump.h"

int main(int argc, char **argv) {

    char test[] = "Grundlagen Betriebssysteme und Systemsoftware.\0";
    hexdump(stdin, test, strlen(test));

    return EXIT_SUCCESS;
}