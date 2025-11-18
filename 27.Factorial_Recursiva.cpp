#include <iostream>
using namespace std;

int main() {
    int N, i, factorial;

    cout << "Ingrese un numero entero: ";
    cin >> N;

    factorial = 1;

    if (N < 0) {
        cout << "El factorial no esta definido para numeros negativos." << endl;
    } else {
        for (i = 1; i <= N; i = i + 1) {
            factorial = factorial * i;
        }

        cout << "El factorial de " << N << " es: " << factorial << endl;
    }

    return 0;
}
