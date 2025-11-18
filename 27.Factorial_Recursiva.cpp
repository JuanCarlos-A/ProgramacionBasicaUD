#include <iostream>
using namespace std;

int factorialRec(int n) {
    if (n == 0 || n == 1) {
        return 1;                 // Caso base
    }
    return n * factorialRec(n - 1); // Llamada recursiva
}

int main() {
    int N;

    cout << "Ingrese un numero entero: ";
    cin >> N;

    if (N < 0) {
        cout << "El factorial no esta definido para numeros negativos." << endl;
    } else {
        cout << "El factorial de " << N << " es: " << factorialRec(N) << endl;
    }

    return 0;
}
