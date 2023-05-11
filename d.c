#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char palabra[10];
}coincidentes;
int main(){
    setlocale("es_ES.UTF-8");
    int i, j=0, n, contador, x, words=1, k=0, palabrascoincidentes=0;
    char texto[1000];
    FILE *ap;
    printf("Ingrese la longitud de las palabras a encontrar: ");
    scanf("%d", &n);
    fflush(stdin);
    ap=fopen("archivo.txt", "r");
    if(ap==NULL){
        printf("Error en el archivo");
        return -1;
    }
    fgets(texto, sizeof(texto), ap);
    x=strlen(texto);
    for (i=0;i<x;i++){
        if(texto[i]==' '){
            words++;
        }
    }
    coincidentes palabritas[words];
    printf("Las palabras coincidentes son:\n");
    for(i=0;i<x;i++){
        if(texto[i]==' '){
            j++;
            k=0;
        }
        if (texto[i]!=' '&&texto[i]!=','&&texto[i]!='.'){
            palabritas[j].palabra[k]=texto[i];
            k++;
            }
    }
    for(i=0;i<words;i++){
        if(strlen(palabritas[i].palabra)==n){
            palabrascoincidentes++;
            printf("%s\n", palabritas[i].palabra);
        }
    }
    fclose(ap);
    return 0;
}
