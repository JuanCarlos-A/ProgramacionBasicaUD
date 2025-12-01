#include <iostream>
using namespace std;

long long movimientos = 0;


void hanoirecursivo(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        movimientos++;
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
        return;
    }

    hanoirecursivo(n - 1, origen, auxiliar, destino);

    movimientos++;
    cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;

    hanoirecursivo(n - 1, auxiliar, destino, origen);
}

int main() {
    int N;
    cout << "Ingrese el número de discos: ";
    cin >> N;

    hanoirecursivo(N, 'A', 'C', 'B');

    cout << "Número total de movimientos: " << movimientos << endl;

    return 0;
}
