#include <iostream>
using namespace std;

int ackerman_recursivo(int m, int n){
    if(m == 0){
        return n + 1;
    } else if(m > 0 && n == 0){
        return ackerman_recursivo(m - 1, 1);
    } else if(m > 0 && n > 0){
        return ackerman_recursivo(m-1, ackerman_recursivo(m, n - 1));
    }
}


int main(){
    cout << "Vamos a utilizar la funcion de Ackerman, conocida como la funcion mas rapida en crecer" << endl;
    int m, n;
    cout << "Ingrese el valor de m: ";
    cin >> m;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    while (m < 0 || n < 0) {
        cout << "Los valores de m y n deben ser enteros no negativos." << endl;
        cout << "Ingrese el valor de m: ";
        cin >> m;
        cout << "Ingrese el valor de n: ";
        cin >> n;
    }

    cout << "El resultado es : " << ackerman_recursivo(m, n) << endl;
      
    return 0;
}