#include <iostream>
#include <cmath> // Para pow()
using namespace std;

int main() {
    double c, I, i2, VF;
    int n2, N, P, resp, opc;

    cout << "Bienvenido Usuario a la Entidad Financiera" << endl;
    cout << " *-Nada puede malir sal-* " << endl;
    cout << "Antes de continuar recordamos que trabajamos con una tasa del 12% de interes nominal anual." << endl;

    cout << "¿Desea continuar con el proceso? (1. Si o 2. No)" << endl;
    cout << "(Poner el numero de la opcion): ";
    cin >> resp;

    // Condicional para comparar la respuesta del usuario
    if (resp == 1) {

        cout << "Ingrese el capital inicial que desea invertir: ";
        cin >> c;

        // Validamos que el usuario no haya ingresado un capital negativo
        if (c > 0) {

            I = 12.0 / 100.0;  // Convertir tasa nominal anual a decimal (12%)

            cout << "Ingrese el numero de años (min. 1 año): ";
            cin >> n2;

            if (n2 > 0) {

                cout << "Seleccione el periodo de capitalizacion: " << endl;
                cout << "1) Mensual" << endl;
                cout << "2) Trimestral" << endl;
                cout << "3) Semestral" << endl;
                cout << "4) Anual" << endl;
                cin >> opc;

                // Determinar P según el sistema de capitalización
                switch (opc) {
                    case 1: P = 12; break;
                    case 2: P = 4; break;
                    case 3: P = 2; break;
                    case 4: P = 1; break;
                    default:
                        cout << "Opcion no valida." << endl;
                        P = 0;
                        break;
                }

                if (P != 0) {
                    // Cálculos
                    i2 = I / P;
                    N = P * n2;
                    VF = c * pow((1 + i2), N);

                    // Salida de resultados
                    cout << "Capital inicial: " << c << endl;
                    cout << "Tasa de interes nominal anual: " << I << endl;
                    cout << "Tasa de interes por periodo: " << i2 << endl;
                    cout << "Años: " << n2 << endl;
                    cout << "Numero de periodos capitalizables por año: " << P << endl;
                    cout << "Total de periodos capitalizables: " << N << endl;
                    cout << "Valor final de la inversion: $" << VF << endl;

                } else {
                    cout << "Deberas volver a empezar." << endl;
                }

            } else {
                cout << "En los requisitos el tiempo debe ser minimo un año." << endl;
            }

        } else {
            cout << "El valor almacenado no corresponde, por favor vuelva a intentar." << endl;
        }

    } else {
        cout << "No hay problema, esperamos volver a verlo." << endl;
    }

    return 0;
}
