#include <stdlib.h>
#include <stdio.h>

#include "list.h"

list_t *list_init() {
    list_t *intialisierte_liste = (void *) malloc(sizeof(list_t));
    return intialisierte_liste;
}

struct list_elem *list_insert(list_t *list, char *data) {

    struct list_elem *newElement;
    newElement = (void *) malloc(sizeof(struct list_elem));

    newElement->next = list->first;
    newElement->data = data;

    list->first = newElement;

    return newElement;
}

struct list_elem *list_append(list_t *list, char *data) {
    struct list_elem *newElement = (void *) malloc(sizeof(struct list_elem));

    newElement->data = data;

    struct list_elem *currentElement = list->first;

    if(currentElement == NULL) {
        list->first = newElement;
    }
    else {
        while(currentElement->next != NULL) {
            currentElement = currentElement->next;
        }
        currentElement->next = newElement;
    }
    return newElement;
}

int list_remove(list_t *list, struct list_elem *elem) {

    struct list_elem *currentElement = list->first;

    // Am Anfang kein Element
    if(currentElement==NULL){
        return -1;
    }

    // Am Anfang das richtige Element
    if(currentElement == elem){
        if(currentElement->next != NULL){
            list->first = currentElement->next;
        }
        else{
            list->first = NULL;
        }
        return 0;
    }

    // Am Anfang das nächste Element das richtige
    if(currentElement->next == elem){
        if(currentElement->next->next != NULL){
            currentElement->next = currentElement->next->next;
        }
        else{
            currentElement->next = NULL;
        }
        return 0;
    }

    // Die Liste durchgehen
    while (currentElement->next != NULL) {
        if (currentElement->next == elem){
            // überprüfen, ob es ein übernachstes Element gibt
            if(currentElement->next->next == NULL){
                currentElement->next = NULL;
            }
            else{
                currentElement->next = currentElement->next->next;
            }
            return 0;
        }
        else {
            currentElement = currentElement->next;
        }
    }
    return -1;
}

void list_finit (list_t *list){
    // eigentlich müsste man die Liste noch löschen
    free(list);
    free(list->first);
    free(list->last);
    list = list_init();
}

void list_print(list_t *list, void (*print_elem) (char *)){
    struct list_elem *currentElement = (void*) malloc(sizeof(struct list_elem));
    currentElement = list->first;
    int counter = 1;

    while(currentElement != NULL){
        printf("%d:", counter);
        print_elem(currentElement->data);
        printf("\n");
        counter++;
        currentElement = currentElement->next;
    }
}