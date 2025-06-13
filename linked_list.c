#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct Nodo {
    int dato;
    struct Nodo* next;
} Nodo;

static Nodo* cabeza = NULL;
static int tamaño_lista = 0;

void linked_list_init() {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* temporal = actual;
        actual = actual->next;
        free(temporal);
    }
    cabeza = NULL;
    tamaño_lista = 0;
}

int linked_list_append(int dato) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo_nodo) return -1;

    nuevo_nodo->dato = dato;
    nuevo_nodo->next = NULL;

    if (cabeza == NULL) {
        cabeza = nuevo_nodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->next != NULL) {
            actual = actual->next;
        }
        actual->next = nuevo_nodo;
    }
    tamaño_lista++;
    return 0;
}

int linked_list_prepend(int dato) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo_nodo) return -1;

    nuevo_nodo->dato = dato;
    nuevo_nodo->next = cabeza;
    cabeza = nuevo_nodo;
    tamaño_lista++;
    return 0;
}

int linked_list_remove(int dato) {
    Nodo* actual = cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL) {
        if (actual->dato == dato) {
            if (anterior == NULL) {
                cabeza = actual->next;
            } else {
                anterior->next = actual->next;
            }
            free(actual);
            tamaño_lista--;
            return 0;
        }
        anterior = actual;
        actual = actual->next;
    }
    return -1;
}

int linked_list_contains(int dato) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        if (actual->dato == dato) return 1;
        actual = actual->next;
    }
    return 0;
}

unsigned int linked_list_size() {
    return tamaño_lista;
}

void linked_list_print() {
    Nodo* actual = cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->next;
    }
    printf("\n");
}