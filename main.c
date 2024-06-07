#include <stdio.h>
#include <stdlib.h>

// Structure pour le tableau du simplexe
typedef struct {
    int rows;
    int cols;
    double **data;
} SimplexTableau;

// Fonction pour créer un tableau du simplexe
SimplexTableau* createTableau(int rows, int cols) {
    SimplexTableau *tableau = (SimplexTableau*)malloc(sizeof(SimplexTableau));
    tableau->rows = rows;
    tableau->cols = cols;
    tableau->data = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        tableau->data[i] = (double*)malloc(cols * sizeof(double));
    }
    return tableau;
}

// Fonction pour libérer la mémoire du tableau du simplexe
void freeTableau(SimplexTableau *tableau) {
    for (int i = 0; i < tableau->rows; i++) {
        free(tableau->data[i]);
    }
    free(tableau->data);
    free(tableau);
}

// Lire les entrées de l'utilisateur
void readInput(SimplexTableau *tableau, FILE *input) {
    for (int i = 0; i < tableau->rows - 1; i++) {
        for (int j = 0; j < tableau->cols; j++) {
            fscanf(input, "%lf", &tableau->data[i][j]);
        }
    }
    for (int j = 0; j < tableau->cols - 1; j++) {
        fscanf(input, "%lf", &tableau->data[tableau->rows - 1][j]);
        tableau->data[tableau->rows - 1][j] *= -1; // Minimisation
    }
    tableau->data[tableau->rows - 1][tableau->cols - 1] = 0; // Terme constant de la fonction objectif
}

// Trouver la colonne pivot
int findPivotColumn(SimplexTableau *tableau) {
    int pivotCol = 0;
    for (int j = 1; j < tableau->cols - 1; j++) {
        if (tableau->data[tableau->rows - 1][j] < tableau->data[tableau->rows - 1][pivotCol]) {
            pivotCol = j;
        }
    }
    return pivotCol;
}

// Trouver la ligne pivot
int findPivotRow(SimplexTableau *tableau, int pivotCol) {
    int pivotRow = -1;
    double minRatio = 1e20;
    for (int i = 0; i < tableau->rows - 1; i++) {
        if (tableau->data[i][pivotCol] > 0) {
            double ratio = tableau->data[i][tableau->cols - 1] / tableau->data[i][pivotCol];
            if (ratio < minRatio) {
                minRatio = ratio;
                pivotRow = i;
            }
        }
    }
    return pivotRow;
}

// Effectuer le pivot
void performPivot(SimplexTableau *tableau, int pivotRow, int pivotCol) {
    double pivotValue = tableau->data[pivotRow][pivotCol];
    for (int j = 0; j < tableau->cols; j++) {
        tableau->data[pivotRow][j] /= pivotValue;
    }
    for (int i = 0; i < tableau->rows; i++) {
        if (i != pivotRow) {
            double factor = tableau->data[i][pivotCol];
            for (int j = 0; j < tableau->cols; j++) {
                tableau->data[i][j] -= factor * tableau->data[pivotRow][j];
            }
        }
    }
}

// Vérifier si la solution est optimale
int isOptimal(SimplexTableau *tableau) {
    for (int j = 0; j < tableau->cols - 1; j++) {
        if (tableau->data[tableau->rows - 1][j] < 0) {
            return 0;
        }
    }
    return 1;
}

// Algorithme du simplexe
void simplex(SimplexTableau *tableau) {
    while (!isOptimal(tableau)) {
        int pivotCol = findPivotColumn(tableau);
        int pivotRow = findPivotRow(tableau, pivotCol);
        if (pivotRow == -1) {
            printf("Problème non borné.\n");
            return;
        }
        performPivot(tableau, pivotRow, pivotCol);
    }
}

// Afficher le tableau du simplexe
void printTableau(SimplexTableau *tableau) {
    for (int i = 0; i < tableau->rows; i++) {
        for (int j = 0; j < tableau->cols; j++) {
            printf("%10.2f ", tableau->data[i][j]);
        }
        printf("\n");
    }
}

// Fonction principale
int main() {
    FILE *input = fopen("input.txt", "r");
    int constraints, variables;

    fscanf(input, "%d", &constraints);
    fscanf(input, "%d", &variables);

    // Ajouter une ligne pour la fonction objectif
    int rows = constraints + 1;
    // Ajouter une colonne pour le terme constant
    int cols = variables +1;

    SimplexTableau *tableau = createTableau(rows, cols);
    readInput(tableau, input);
    fclose(input);

    printf("Tableau initial:\n");
    printTableau(tableau);

    simplex(tableau);

    printf("Tableau optimal:\n");
    printTableau(tableau);

    freeTableau(tableau);

    return 0;
}