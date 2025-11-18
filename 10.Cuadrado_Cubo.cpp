#include <iostream>
using namespace std;

int cuadrado(int n) {
    return n * n;
}

int cubo(int n) {
    return n * n * n;
}


int main() {
    cout << "Numero  | Cuadrado | Cubo" << endl;
    cout << "--------------------------" << endl;
    for (int i = 0; i <= 99; ++i){
        cout << i << " | " << cuadrado(i) << " | " << cubo(i) << endl;
    }
    return 0;
}