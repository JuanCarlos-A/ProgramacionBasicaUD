#include <iostream>
using namespace std;

int main() {

    const int N = 3;
    double A[N][N], B[N][N];
    double C[N][N], D[N][N], E[N][N];

    // Matrices aumentadas para el método Gauss-Jordan
    double augA[N][2*N];
    double augB[N][2*N];

    // ----------------------------------
    // Entrada de datos
    // ----------------------------------
    cout << "Ingrese los elementos de la matriz A (3x3):\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    cout << "Ingrese los elementos de la matriz B (3x3):\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> B[i][j];
        }
    }

    // ----------------------------------
    // 1. Suma C = A + B
    // ----------------------------------
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // ----------------------------------
    // 2. Resta D = A - B
    // ----------------------------------
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            D[i][j] = A[i][j] - B[i][j];
        }
    }

    // ----------------------------------
    // 3. Multiplicación E = A * B
    // ----------------------------------
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            E[i][j] = 0;
            for (int k = 0; k < N; k++){
                E[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // ----------------------------------
    // 4. Inversa de A usando Gauss-Jordan
    // ----------------------------------

    // Construimos la matriz aumentada [A | I]
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            augA[i][j] = A[i][j];
        }
        for (int j = N; j < 2*N; j++){
            augA[i][j] = (j - N == i) ? 1 : 0;
        }
    }

    // Aplicación del método Gauss-Jordan
    for (int col = 0; col < N; col++){

        // Normalizar pivote
        double pivote = augA[col][col];
        if (pivote == 0){
            cout << "\nA no tiene inversa.\n";
            return 0;
        }

        for (int j = 0; j < 2*N; j++){
            augA[col][j] /= pivote;
        }

        // Hacer ceros en las demás filas
        for (int fila = 0; fila < N; fila++){
            if (fila != col){
                double factor = augA[fila][col];
                for (int j = 0; j < 2*N; j++){
                    augA[fila][j] -= factor * augA[col][j];
                }
            }
        }
    }

    // ----------------------------------
    // 5. Inversa de B usando Gauss-Jordan
    // ----------------------------------

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            augB[i][j] = B[i][j];
        }
        for (int j = N; j < 2*N; j++){
            augB[i][j] = (j - N == i) ? 1 : 0;
        }
    }

    for (int col = 0; col < N; col++){
        double pivote = augB[col][col];
        if (pivote == 0){
            cout << "\nB no tiene inversa.\n";
            return 0;
        }
        for (int j = 0; j < 2*N; j++){
            augB[col][j] /= pivote;
        }
        for (int fila = 0; fila < N; fila++){
            if (fila != col){
                double factor = augB[fila][col];
                for (int j = 0; j < 2*N; j++){
                    augB[fila][j] -= factor * augB[col][j];
                }
            }
        }
    }

    // ----------------------------------
    // Mostrar resultados
    // ----------------------------------

    cout << "\nMatriz C = A + B\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz D = A - B\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz E = A * B\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << E[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nInversa de A\n";
    for (int i = 0; i < N; i++){
        for (int j = N; j < 2*N; j++){
            cout << augA[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nInversa de B\n";
    for (int i = 0; i < N; i++){
        for (int j = N; j < 2*N; j++){
            cout << augB[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
