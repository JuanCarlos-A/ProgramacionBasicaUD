#include <iostream>
using namespace std;

int main() {
    int A, B, C, mcdAB, mcdABC, mcmAB, mcmABC, aux1, aux2, r;

    cout << "Ingrese el valor de A: ";
    cin >> A;
    cout << "Ingrese el valor de B: ";
    cin >> B;
    cout << "Ingrese el valor de C: ";
    cin >> C;

    // --- Calcular MCD(A,B) ---
    aux1 = A;
    aux2 = B;
    while (aux2 != 0) {
        r = aux1 % aux2;
        aux1 = aux2;
        aux2 = r;
    }
    mcdAB = aux1;

    // --- Calcular MCD(mcdAB, C) ---
    aux1 = mcdAB;
    aux2 = C;
    while (aux2 != 0) {
        r = aux1 % aux2;
        aux1 = aux2;
        aux2 = r;
    }
    mcdABC = aux1;

    // --- Calcular mcm(A, B) ---
    mcmAB = (A * B) / mcdAB;

    // --- Calcular MCD(mcmAB, C) ---
    aux1 = mcmAB;
    aux2 = C;
    while (aux2 != 0) {
        r = aux1 % aux2;
        aux1 = aux2;
        aux2 = r;
    }

    // --- Calcular mcm(mcmAB, C) ---
    mcmABC = (mcmAB * C) / aux1;

    cout << "El MCD de A, B y C es: " << mcdABC << endl;
    cout << "El mcm de A, B y C es: " << mcmABC << endl;

    return 0;
}
