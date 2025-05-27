#include <iostream>

using namespace std;

int main() {

    char opcion;
    cout << "Opciones disponibles:" << endl;
    cout << "(A) Amigos" << endl;
    cout << "(B) Bipartito" << endl;
    cout << "(C) Salir" << endl;
    cout << endl << "Ingrese la opcion: ";
    cin >> opcion;
    cout << endl;

    if (opcion == 'A' || opcion == 'a') {
        int num1;
        cout << "Escriba el primer numero: ";
        cin >> num1;

        int num2;
        cout << "Escriba el segundo numero: ";
        cin >> num2;

        int suma_divisores_1 = 0;
        for (int i = 1; i < num1; i++)
        {
            if (num1 % i == 0) {
                suma_divisores_1 = suma_divisores_1 + i;
            }
        }

        int suma_divisores_2 = 0;
        for (int i = 1; i < num2; i++)
        {
            if (num2 % i == 0) {
                suma_divisores_2 = suma_divisores_2 + i;
            }
        }

        if (suma_divisores_1 == num2 && suma_divisores_2 == num1) {
            cout << num1 << " y " << num2 << " son amigos.";
        } else {
            cout << num1 << " y " << num2 << " no son amigos.";
        }
    }
    else if (opcion == 'B' || opcion == 'b') {
        int numero;
        cout << "Escriba el numero: ";
        cin >> numero;

        int digito1 = -1;
        int digito2 = -1;
        int digito3 = -1;
        int restante = numero < 0 ? -numero : numero;

        while (restante > 0) {
            int digitoActual = restante % 10;
            restante = restante / 10;

            if (digito1 == -1) {
                digito1 = digitoActual;
            }
            else if (digitoActual != digito1 && digito2 == -1) {
                digito2 = digitoActual;
            }
            else if (digitoActual != digito1 && digitoActual != digito2) {
                digito3 = digitoActual;
                break;
            }
        }

        if (digito1 != -1 && digito2 != -1 && digito3 == -1) {
            cout << "El numero " << numero << " si es bipartito." << endl;
        }
        else {
            cout << "El numero " << numero << " no es bipartito." << endl;
        }
    }
    else {
        cout << "Ha decidido salir del programa." << endl;
    }

}