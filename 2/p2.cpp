#include <iostream>

using namespace std;

int main() {

    char opcion;
    cout << "Opciones disponibles:" << endl;
    cout << "(V) Vuelo" << endl;
    cout << "(D) Distancia" << endl;
    cout << "(T) Terminar" << endl;
    cout << endl << "Ingrese la opcion: ";
    cin >> opcion;
    cout << endl;

    if (opcion == 'V' || opcion == 'v') {
        int hora_despegue;
        cout << "Ingrese la hora de despegue (1-12):" << endl;
        cin >> hora_despegue;

        int minutos_despegue;
        cout << "Ingrese los minutos de despegue (1-59):" << endl;
        cin >> minutos_despegue;

        char meridiano_despegue;
        cout << "Ingrese el meridiano de despegue (A-P):" << endl;
        cin >> meridiano_despegue;

        if (hora_despegue >= 13 || minutos_despegue >= 60 || (meridiano_despegue != 'A' && meridiano_despegue != 'a' && meridiano_despegue != 'P' && meridiano_despegue != 'p')) {
            cout << "Error: hora de despegue ingresada invalida." << endl;
        }
        else {
            int horas_vuelo;
            cout << "Ingrese las horas de vuelo:" << endl;
            cin >> horas_vuelo;

            int minutos_vuelo;
            cout << "Ingrese los minutos de vuelo:" << endl;
            cin >> minutos_vuelo;

            int hora_despeje_24hs;
            if (hora_despegue == 12 && (meridiano_despegue == 'A' || meridiano_despegue == 'a')) {
                hora_despeje_24hs = 0;
            }
            else if (hora_despegue == 12 && (meridiano_despegue == 'P' || meridiano_despegue == 'p')) {
                hora_despeje_24hs = 12;
            }
            else {
                hora_despeje_24hs =
                    meridiano_despegue == 'P' || meridiano_despegue == 'p' ? hora_despegue + 12 : hora_despegue;
            }

            int hora_final_24hs = hora_despeje_24hs + horas_vuelo + minutos_vuelo / 60;
            int minutos_final = minutos_despegue + (minutos_vuelo % 60);
            if (minutos_final >= 60) {
                hora_final_24hs++;
                minutos_final = minutos_final - 60;
            }
            bool meridiano_pm = hora_final_24hs >= 13;
            int hora_final_12hs = meridiano_pm ? hora_final_24hs - 12 : hora_final_24hs;

            cout << endl;
            if (hora_final_24hs >= 24) {
                cout << "Error: el vuelo aterrizara antes de despegar (asumiendo que el vuelo tiene que despegar y aterrizar el mismo dia, la hora de aterrizaje sucede antes de la hora de despegue)." << endl;
            }
            else {
                cout << "Tiempo de vuelo total: " << horas_vuelo << " hora(s) y " << minutos_vuelo << " minuto(s)" << endl;
                cout << "El vuelo aterrizara a las: " << hora_final_12hs << ":" << (minutos_final < 10 ? "0" : "") << minutos_final << (meridiano_pm == true ? " P.M" : " A.M");
            }
        }
    }
    else if (opcion == 'D' || opcion == 'd') {
        int num1;
        cout << "Ingrese el primer numero: ";
        cin >> num1;

        int num2;
        cout << "Ingrese el segundo numero: ";
        cin >> num2;

        int num3;
        cout << "Ingrese el tercer numero: ";
        cin >> num3;

        int distancia_1_y_2 = (num1 > num2) ? (num1 - num2) : (num2 - num1);
        int distancia_1_y_3 = (num1 > num3) ? (num1 - num3) : (num3 - num1);
        int distancia_2_y_3 = (num2 > num3) ? (num2 - num3) : (num3 - num2);

        int distancia_maxima;
        if (distancia_1_y_2 >= distancia_1_y_3) {
            if (distancia_1_y_2 >= distancia_2_y_3) {
                distancia_maxima = distancia_1_y_2;
            }
            else {
                distancia_maxima = distancia_2_y_3;
            }
        }
        else {
            if (distancia_1_y_3 >= distancia_2_y_3) {
                distancia_maxima = distancia_1_y_3;
            }
            else {
                distancia_maxima = distancia_2_y_3;
            }
        }

        cout << endl;

        if (distancia_maxima == 0) {
            cout << "No hay distancia entre " << num1 << ", " << num2 << " y " << num3 << ", los numeros son iguales." << endl;
        }
        else {
            cout << "Los numeros mas alejados y su distancia son:" << endl;
            if (distancia_maxima == distancia_1_y_2) {
                cout << num1 << " y " << num2 << " con distancia de " << distancia_1_y_2 << endl;
            }
            if (distancia_maxima == distancia_1_y_3) {
                cout << num1 << " y " << num3 << " con distancia de " << distancia_1_y_3 << endl;
            }
            if (distancia_maxima == distancia_2_y_3) {
                cout << num2 << " y " << num3 << " con distancia de " << distancia_2_y_3 << endl;
            }
        }

    }
    else {
        cout << "Error: programa terminado." << endl;
    }

}