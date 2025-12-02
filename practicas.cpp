#include "iostream"
using namespace std;

int main(){
    int matriz[10] = {2,4,6,8,10,12,14,16,18,20};
    int * ptr = matriz;

    cout << "El valor del puntero es: " << *ptr << endl;
    cout << "El valor de laa memoria de matriz[0] es: " << ptr << endl;
    cout << ptr[0]<< endl;
    cout << matriz << endl;


    for(int i = 0; i < 5; i++){
        ptr = ptr + 1;
        cout << ptr << " - " << *ptr << endl;
    }

    cout << "El valor del puntero despues de avanzar 10 posiciones es: " << *ptr << endl;
}
