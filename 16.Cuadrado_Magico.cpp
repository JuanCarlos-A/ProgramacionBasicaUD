#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    int A[3][3];
    int usados[10] = {0};
    int sumaFila, sumaCol, sumaDiag1, sumaDiag2;
    bool esMagico = false;

    srand(time(0)); // Semilla aleatoria

    while (!esMagico) {

        // Llenar con números aleatorios del 1 al 9 sin repetir
        for (int i = 1; i <= 9; i++) usados[i] = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                int num;
                do {
                    num = rand() % 9 + 1;
                } while (usados[num] == 1);

                usados[num] = 1;
                A[i][j] = num;
            }
        }

        // Revisar filas
        esMagico =
            (A[0][0] + A[0][1] + A[0][2] == 15) &&
            (A[1][0] + A[1][1] + A[1][2] == 15) &&
            (A[2][0] + A[2][1] + A[2][2] == 15) &&

            // Revisar columnas
            (A[0][0] + A[1][0] + A[2][0] == 15) &&
            (A[0][1] + A[1][1] + A[2][1] == 15) &&
            (A[0][2] + A[1][2] + A[2][2] == 15) &&

            // Revisar diagonales
            (A[0][0] + A[1][1] + A[2][2] == 15) &&
            (A[0][2] + A[1][1] + A[2][0] == 15);
    }

    // Imprimir el cuadrado mágico
    cout << "\nCuadrado Magico generado:\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
