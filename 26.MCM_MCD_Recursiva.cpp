#include <iostream>
using namespace std;

int mcdRec(int a, int b) {
    if (b == 0) return a;   // Caso base
    return mcdRec(b, a % b); // Llamada recursiva
}


int mcmRec(int a, int b) {
    return (a * b) / mcdRec(a, b);
}

int main() {

    int A, B, C;

    cout << "Ingrese el valor de A: ";
    cin >> A;

    cout << "Ingrese el valor de B: ";
    cin >> B;

    cout << "Ingrese el valor de C: ";
    cin >> C;


    int mcdAB = mcdRec(A, B);
    int mcdABC = mcdRec(mcdAB, C);


    int mcmAB = mcmRec(A, B);
    int mcmABC = mcmRec(mcmAB, C);

    cout << "El MCD de A, B y C es: " << mcdABC << endl;
    cout << "El mcm de A, B y C es: " << mcmABC << endl;

    return 0;
}
