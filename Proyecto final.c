// Ejercico de la práctica elaborado con funciones, hecho para una matriz de 100 pueblos y 8 bebidas respectivamente, por lo que se tienen que ingresar muchos datos
#include <stdio.h>

#define PUEBLOS 100
#define BEBIDAS 8

void inicializarMatriz(int arr[PUEBLOS][BEBIDAS]) {
    for (int i = 0; i < PUEBLOS; i++) {
        for (int j = 0; j < BEBIDAS; j++) {
            arr[i][j] = 0;
        }
    }
}

void llenarMatriz(int arr[PUEBLOS][BEBIDAS]) {
    int var1, var2;
    for (int i = 0; i < PUEBLOS; i++) {
        printf("Dame la bebida correspondiente del pueblo %d: ", i);
        scanf("%d", &var1);
        while (var1 != -1) {
            printf("Dame la cantidad en litros: ");
            scanf("%d", &var2);
            arr[i][var1] = var2;
            printf("Dame otra bebida: ");
            scanf("%d", &var1);
        }
    }
}

int bebidaMasConsumida(int arr[PUEBLOS][BEBIDAS]) {
    int total[BEBIDAS] = {0};
    for (int j = 0; j < BEBIDAS; j++) {
        for (int i = 0; i < PUEBLOS; i++) {
            total[j] += arr[i][j];
        }
    }

    int max = 0, bebida = 0;
    for (int i = 0; i < BEBIDAS; i++) {
        if (total[i] > max) {
            max = total[i];
            bebida = i;
        }
    }
    printf("La bebida %d es la bebida que más se consume con %d litros.\n", bebida, max);
    return bebida;
}

int bebidaMasConsumidaAlcohol(int arr[PUEBLOS][BEBIDAS]) {
    int total[BEBIDAS] = {0};
    for (int i = 0; i < BEBIDAS; i++) {
        if (i != 1 && i != 6) { 
            for (int j = 0; j < PUEBLOS; j++) {
                total[i] += arr[j][i];
            }
        }
    }

    int max = 0, bebida = 0;
    for (int i = 0; i < BEBIDAS; i++) {
        if (total[i] > max) {
            max = total[i];
            bebida = i;
        }
    }
    printf("La bebida alcohólica %d es la más consumida con %d litros.\n", bebida, max);
    return bebida;
}

int puebloMasAlcohol(int arr[PUEBLOS][BEBIDAS]) {
    int total[PUEBLOS] = {0};

    for (int i = 0; i < PUEBLOS; i++) {
        for (int j = 0; j < BEBIDAS; j++) {
            if (j != 1 && j != 6) {
                total[i] += arr[i][j];
            }
        }
    }

    int max = 0, pueblo = 0;
    for (int i = 0; i < PUEBLOS; i++) {
        if (total[i] > max) {
            max = total[i];
            pueblo = i;
        }
    }
    printf("El pueblo %d consume más alcohol con %d litros.\n", pueblo, max);
    return pueblo;
}

int main() {
    int arr[PUEBLOS][BEBIDAS];
    
    inicializarMatriz(arr);
    printf("Se inicializó la matriz de forma correcta.\n");

    llenarMatriz(arr);
    bebidaMasConsumida(arr);
    bebidaMasConsumidaAlcohol(arr);
    puebloMasAlcohol(arr);

    return 0;
}
