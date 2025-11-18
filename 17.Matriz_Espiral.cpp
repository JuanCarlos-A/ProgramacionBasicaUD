#include <iostream>
using namespace std;

int main() {

    int M, N;

    cout << "Ingrese el numero de filas (M): ";
    cin >> M;

    cout << "Ingrese el numero de columnas (N): ";
    cin >> N;

    int A[M][N];

    int inicioFila = 0, finFila = M - 1;
    int inicioCol = 0, finCol = N - 1;
    int num = 1;

    while (inicioFila <= finFila && inicioCol <= finCol) {

        // Izquierda → derecha
        for (int j = inicioCol; j <= finCol; j++) {
            A[inicioFila][j] = num++;
        }
        inicioFila++;

        // Arriba → abajo
        for (int i = inicioFila; i <= finFila; i++) {
            A[i][finCol] = num++;
        }
        finCol--;

        // Derecha → izquierda
        if (inicioFila <= finFila) {
            for (int j = finCol; j >= inicioCol; j--) {
                A[finFila][j] = num++;
            }
            finFila--;
        }

        // Abajo → arriba
        if (inicioCol <= finCol) {
            for (int i = finFila; i >= inicioFila; i--) {
                A[i][inicioCol] = num++;
            }
            inicioCol++;
        }
    }

    // Mostrar matriz
    cout << "\nMatriz en forma espiral:\n\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
