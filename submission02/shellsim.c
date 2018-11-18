#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <windows.h>

#include "list.h"

struct list_elem {
        struct list_elem *next ; // Zeiger auf das nächste Element
        char *data ; // Zeiger auf ein Datenobjekt
} ;

typedef struct list {
        struct list_elem *first ; // erstes Elemten in der Liste
        struct list_elem *last ; // letztes Element in der Liste
} list_t ;

int main() {


    return EXIT_SUCCESS;
}
