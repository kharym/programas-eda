#include <stdio.h>
#include <stdlib.h>

/* Total de elementos o datos que contiene el archivo a leer (para no usar n�meros m�gicos)*/
#define ELEMENTOS 9

/* Estructura que almacenar� los datos de cada rengl�n del archivo.
 * Como no supe qu� datos representaban, le puse esos nombres.
 * Se que suena algo er�tico y pervertido el nombre del campo 'ano' pero nimodo ^^.
 */
typedef struct{
        int ano;
        int mes;
        int dato;
}Vectorin;

/* Arreglo de punteros a estructuras Vectorin */
Vectorin *vectores[ELEMENTOS];
/* apuntador al archivo a leer, en �ste caso 'Datos' */
FILE *archivo;

int main(void){

        /* Contador que utilizaremos para iterar sobre el arreglo */
        register int i;

        /*Abrimos archivo y verificamos que se haya abierto correctamente */
        puts("Abriendo el archivo para lectura...");
        archivo = fopen("Datos.txt", "r");

        if (!archivo){
                puts("Error al leer el archivo \'Datos\'");
                exit (EXIT_FAILURE);
        }

        /* Reservamos memoria din�micamente para cada apuntador del arreglo */
        puts("Reservando memoria para los datos en el vector...");
        for(i = 0; i < ELEMENTOS; i++){
                vectores[i] = (Vectorin *)malloc(sizeof(Vectorin));
                if (vectores[i] == NULL){
                        printf("Error al reservar memoria, no hay suficiente memoria para el elemento %d", i+1);
                        exit (EXIT_FAILURE);
                }
        }

        /* Leemos el archivo rengl�n por rengl�n y lo vamos almacenando
         * en cada elemento (�tem) del arreglo.
         *
         * Para m�s espec�fico, puede ser fscanf(archivo, "%4d %1d %2d"...);
         */
        puts("Leyendo los datos y almacen�ndolos en el vector...");
        i = 0;
        while (!feof(archivo) && !ferror(archivo)){
                fscanf(archivo, "%d %d %d", &vectores[i]->ano,
                                &vectores[i]->mes, &vectores[i]->dato);
                i++;
        }

        /* Imprimimos los datos */
        puts("\nDatos cargados con �xito\n");
        for(i = 0; i < ELEMENTOS; i++){
                printf("%10s%6d %10s%2d %10s%4d\n", "A�o:", vectores[i]->ano,
                                "Mes:", vectores[i]->mes, "Dato:", vectores[i]->dato);
        }

        /* Liberamos la memoria asignada anteriormente
         * para c�da uno de los elementos y cerramos el archivo
         */
        for(i = 0; i < ELEMENTOS; i++)
                free(vectores[i]);

        fclose(archivo);
        return EXIT_SUCCESS;
}
