// Para este ejercicio se modificó el codigo de forma que se manejaran 5 pueblos y 8 bebidas respectivamente, asi mismo se introdujeron datos aleatorios en lugar de ser escaneados, por lo que al correr el programa en un compilador, automaticamente se obtienen los resultados.
#include <stdio.h>

#define PUEBLOS 5
#define BEBIDAS 8

// Opcional: nombres para imprimir
const char* nombresBebidas[BEBIDAS] = {
    "Natural", "Refresco", "Vino", "Cerveza", "Whisky", "Licores", "Energeticos", "Combinados"
};

typedef struct {
    int consumo[BEBIDAS];  // consumo[i] representa litros de la bebida i
} Pueblo;

void inicializarPueblos(Pueblo pueblos[PUEBLOS]) {
    for (int i = 0; i < PUEBLOS; i++)
        for (int j = 0; j < BEBIDAS; j++)
            pueblos[i].consumo[j] = 0;
}

// Datos precargados para pruebas (valores aleatorios simples)
void llenarDatosPrueba(Pueblo pueblos[PUEBLOS]) {
    int datos[PUEBLOS][BEBIDAS] = {
        {5, 2, 0, 3, 4, 1, 0, 2},
        {3, 1, 2, 2, 3, 3, 0, 0},
        {0, 5, 3, 1, 2, 2, 1, 4},
        {4, 0, 1, 2, 2, 1, 0, 3},
        {2, 1, 0, 0, 5, 4, 0, 1}
    };

    for (int i = 0; i < PUEBLOS; i++)
        for (int j = 0; j < BEBIDAS; j++)
            pueblos[i].consumo[j] = datos[i][j];
}

void bebidaMasConsumida(Pueblo pueblos[PUEBLOS]) {
    int total[BEBIDAS] = {0};

    for (int i = 0; i < PUEBLOS; i++)
        for (int j = 0; j < BEBIDAS; j++)
            total[j] += pueblos[i].consumo[j];

    int max = 0, bebida = 0;
    for (int i = 0; i < BEBIDAS; i++) {
        if (total[i] > max) {
            max = total[i];
            bebida = i;
        }
    }

    printf("La bebida más consumida es: %s (%d litros).\n", nombresBebidas[bebida], max);
}

void bebidaAlcoholicaMasConsumida(Pueblo pueblos[PUEBLOS]) {
    int total[BEBIDAS] = {0};

    for (int i = 0; i < PUEBLOS; i++)
        for (int j = 0; j < BEBIDAS; j++)
            if (j != 1 && j != 6) 
                total[j] += pueblos[i].consumo[j];

    int max = 0, bebida = 0;
    for (int i = 0; i < BEBIDAS; i++) {
        if (total[i] > max) {
            max = total[i];
            bebida = i;
        }
    }

    printf("La bebida alcohólica más consumida es: %s (%d litros).\n", nombresBebidas[bebida], max);
}

void puebloQueMasBebeAlcohol(Pueblo pueblos[PUEBLOS]) {
    int total[PUEBLOS] = {0};

    for (int i = 0; i < PUEBLOS; i++)
        for (int j = 0; j < BEBIDAS; j++)
            if (j != 1 && j != 6)
                total[i] += pueblos[i].consumo[j];

    int max = 0, pueblo = 0;
    for (int i = 0; i < PUEBLOS; i++) {
        if (total[i] > max) {
            max = total[i];
            pueblo = i;
        }
    }

    printf("El pueblo que más consume alcohol es el pueblo %d (%d litros).\n", pueblo, max);
}

int main() {
    Pueblo pueblos[PUEBLOS];

    inicializarPueblos(pueblos);
    llenarDatosPrueba(pueblos);

    bebidaMasConsumida(pueblos);
    bebidaAlcoholicaMasConsumida(pueblos);
    puebloQueMasBebeAlcohol(pueblos);

    return 0;
}
