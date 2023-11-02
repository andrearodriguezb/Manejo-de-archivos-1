
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, numeroActual = 0;
    int maximo, max = 0;
    float suma = 0, media;
    int moda = 0;

    srand(time(NULL));
    printf("Numero de elementos a ordenar:\n"); //Crear arreglo
    scanf("%d", &n);

    int lista[n];
    printf("\n\nLista sin ordenar:\n");

    for (i = 0; i < n; i++) {
        lista[i] = rand() % 30;
        printf(" %d ", lista[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) { //Ordenar arreglo
        numeroActual = lista[i];
        j = i - 1;
        while (j >= 0 && lista[j] > numeroActual) {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = numeroActual;
    }

    printf("\nLista ordenada:\n"); 
    for (i = 0; i < n; i++) {
        printf(" %d ", lista[i]);
    }

    printf("\n\n-Valor minimo: %d", lista[0]); // Valor mínimo (número más pequeño)

    maximo = lista[n - 1]; // Valor máximo
    printf("\n-Valor maximo: %d", maximo);

    for (i = 0; i < n; i++) { // Calcular media
        suma = suma + lista[i];
    }
    media = suma / n;
    printf("\n\n-Media: %f", media);

    int mediana; //Calcular mediana
    if (n % 2 == 0) {
        mediana = (lista[n / 2] + lista[(n / 2) - 1]) / 2;
    } else {
        mediana = lista[n / 2];
    }
    printf("\n-Mediana: %d", mediana);

    int cont1 = 0, cont2 = 0; //Calcular moda

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (lista[i] == lista[j] && i != j) {
                cont1++;
            }

            if (cont1 > cont2) {
                cont2 = cont1;
                moda = lista[i];
            }
        }
        cont1 = 0;
    }
    printf("\n-Moda es: %d\n", moda);

    // Histograma
    printf("\n\n-Histograma:\n");
    int histograma[31]; // Para números del 0 al 30
    for (i = 0; i < 31; i++) {
        histograma[i] = 0;
    }
    for (i = 0; i < n; i++) {
        histograma[lista[i]]++;
    }
    for (i = 0; i < 31; i++) {
        if (histograma[i] > 0) {
            printf("%d: ", i);
            for (j = 0; j < histograma[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
