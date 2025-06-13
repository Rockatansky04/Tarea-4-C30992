Hola, para copilar se va a necesitar ahcer lo siguiente:

1. Compilar cada archivo por separado:
gcc -c stack.c -o stack.o
gcc -c linked_list.c -o linked_list.o
gcc -c main.c -o main.o

2. Enlazar todos los archivos:
gcc stack.o linked_list.o main.o -o programa
