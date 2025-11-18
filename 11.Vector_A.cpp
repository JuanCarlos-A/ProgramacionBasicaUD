#include <iostream>
using namespace std;

int main(){
    int tamano;
    cout << "Ingresa el tamano del vector: ";
    cin >> tamano;

    int vectorA[tamano];

    for(int i = 0; i < tamano; ++i){
        cout << "Ingresa el elemento " << i + 1 << ": ";
        cin >> vectorA[i];
    }

    //Mostramos el vector
    cout << "El vector ingresado es: [";
    for(int i = 0; i < tamano; ++i){
        cout << vectorA[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}