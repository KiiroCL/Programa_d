#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LONGITUD 100

void buscarPalabras(char* nombreArchivo, int longitud);

int main() {
    int longitud;

    printf("Longitud: ");
    scanf("%d", &longitud);

    buscarPalabras("texto.txt", longitud);

    return 0;
}

void buscarPalabras(char* nombreArchivo, int longitud) {
    FILE* archivo;
    char palabra[MAX_LONGITUD];

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    while (fscanf(archivo, "%s", palabra) != EOF) {
        if (strlen(palabra) == longitud) {
            printf("%s\n", palabra);
        }
    }

    fclose(archivo);
}
