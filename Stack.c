#include "stack.h"
#define TamanoMaximo 100

static unsigned int pila[TamanoMaximo];  
static int tope = -1;                    

void stack_init() {
    tope = -1;  
}

int stack_push(unsigned int dato) {
    if (tope >= TamanoMaximo - 1) return -1; 
    pila[++tope] = dato;
    return 0;
}

int stack_pop() {
    if (tope < 0) return -1; 
    return pila[tope--];
}

unsigned int stack_size() {
    return tope + 1;
}

int stack_is_full() {
    return (tope >= TamanoMaximo - 1) ? 1 : 0;
}

int stack_is_empty() {
    return (tope < 0) ? 1 : 0;
}