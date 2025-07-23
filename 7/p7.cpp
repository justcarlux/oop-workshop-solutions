#include <iostream>

using namespace std;

void mostrar_arreglo(int* arreglo, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << *(arreglo + i) << " ";
    }
    cout << endl;
}

bool es_primo(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void cargar(int* matriz, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Ingrese el elemento para la fila " << (i + 1) << " y columna " << (j + 1) << ": ";
            cin >> *(matriz + i * N + j);
        }
    }
}

bool existe_en_arreglo(int* arreglo, int cantidad, int num) {
    for (int i = 0; i < cantidad; i++) {
        if (*(arreglo + i) == num) {
            return true;
        }
    }
    return false;
}

void ordenar_arreglo(int* arreglo, int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (*(arreglo + j) > *(arreglo + j + 1)) {
                int aux = *(arreglo + j);
                *(arreglo + j) = *(arreglo + j + 1);
                *(arreglo + j + 1) = aux;
            }
        }
    }
}

int sacar_primos(int* matriz, int N, int* primos) {
    int cantidad = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num = *(matriz + i * N + j);
            if (es_primo(num) && !existe_en_arreglo(primos, cantidad, num)) {
                *(primos + cantidad) = num;
                cantidad++;
            }
        }
    }
    ordenar_arreglo(primos, cantidad);
    return cantidad;
}

void programa1() {
    int N;
    int matriz[12][12];
    int primos[144];

    cout << "Ingrese N: ";
    cin >> N;

    if (N < 1 || N > 12) {
        cout << "Tamaño incorrecto. Debe ser entre 1 y 12." << endl;
    }
    else {
        cargar(&matriz[0][0], N);
        int cantidad_primos = sacar_primos(&matriz[0][0], N, primos);
        cout << endl << "Se encontro la siguiente cantidad de numeros primos: " << cantidad_primos << endl;
        mostrar_arreglo(primos, cantidad_primos);
    }
}

int strncomp(char* cadena1, char* cadena2, int N) {
    for (int i = 0; i < N; i++) {
        if (*(cadena1 + i) == '\0' || *(cadena2 + i) == '\0') {
            if (*(cadena1 + i) == '\0' && *(cadena2 + i) == '\0') {
                return 0;
            }
            return *(cadena1 + i) - *(cadena2 + i);
        }

        if (*(cadena1 + i) != *(cadena2 + i)) {
            return *(cadena1 + i) - *(cadena2 + i);
        }
    }
    return 0;
}

void programa2() {
    char cadena1[100], cadena2[100];
    int N;

    cout << "Ingrese la primera cadena: ";
    cin >> cadena1;

    cout << "Ingrese la segunda cadena: ";
    cin >> cadena2;

    cout << "Ingrese el numero de caracteres a comparar (N): ";
    cin >> N;

    int resultado = strncomp(cadena1, cadena2, N);
    cout << "Resultado de la comparacion: " << resultado << endl;

    if (resultado == 0) {
        cout << "Los primeros " << N << " caracteres son iguales." << endl;
    }
    else if (resultado < 0) {
        cout << "La primera cadena es menor (en la tabla ASCII) que la segunda (en los primeros " << N << " caracteres)." << endl;
    }
    else {
        cout << "La primera cadena es mayor (en la tabla ASCII) que la segunda (en los primeros " << N << " caracteres)." << endl;
    }
}

void recorrido_espiral(int* matriz, int N, int* arreglo) {
    int inicio_fila = 0, fin_fila = N - 1;
    int inicio_col = 0, fin_col = N - 1;
    int indice = 0;

    while (inicio_fila <= fin_fila && inicio_col <= fin_col) {
        for (int i = inicio_col; i <= fin_col; i++) {
            *(arreglo + indice++) = *(matriz + inicio_fila * N + i);
        }
        inicio_fila++;

        for (int i = inicio_fila; i <= fin_fila; i++) {
            *(arreglo + indice++) = *(matriz + i * N + fin_col);
        }
        fin_col--;

        if (inicio_fila <= fin_fila) {
            for (int i = fin_col; i >= inicio_col; i--) {
                *(arreglo + indice++) = *(matriz + fin_fila * N + i);
            }
            fin_fila--;
        }

        if (inicio_col <= fin_col) {
            for (int i = fin_fila; i >= inicio_fila; i--) {
                *(arreglo + indice++) = *(matriz + i * N + inicio_col);
            }
            inicio_col++;
        }
    }
}

void recorrido_espiral_invertido(int* matriz, int N, int* arreglo) {
    int inicio_fila = 0, fin_fila = N - 1;
    int inicioCol = 0, finCol = N - 1;
    int index = 0;

    while (inicio_fila <= fin_fila && inicioCol <= finCol) {
        for (int i = inicio_fila; i <= fin_fila; i++) {
            *(arreglo + index++) = *(matriz + i * N + inicioCol);
        }
        inicioCol++;

        for (int i = inicioCol; i <= finCol; i++) {
            *(arreglo + index++) = *(matriz + fin_fila * N + i);
        }
        fin_fila--;

        if (inicioCol <= finCol) {
            for (int i = fin_fila; i >= inicio_fila; i--) {
                *(arreglo + index++) = *(matriz + i * N + finCol);
            }
            finCol--;
        }

        if (inicio_fila <= fin_fila) {
            for (int i = finCol; i >= inicioCol; i--) {
                *(arreglo + index++) = *(matriz + inicio_fila * N + i);
            }
            inicio_fila++;
        }
    }
}

void programa3() {
    int N;
    int C[10][10], D[10][10];
    int recorrido_c[100], recorrido_d[100];

    cout << "Ingrese N: ";
    cin >> N;

    if (N < 1 || N > 10) {
        cout << "Tamaño incorrecto. Debe ser entre 1 y 10." << endl;
    }
    else {
        cout << endl << "Ingrese la matriz C:" << endl;
        cargar(&C[0][0], N);

        cout << endl << "Ingrese la matriz D:" << endl;
        cargar(&D[0][0], N);

        recorrido_espiral(&C[0][0], N, recorrido_c);
        recorrido_espiral_invertido(&D[0][0], N, recorrido_d);

        cout << endl << "Arreglo C (recorrido en espiral):" << endl;
        mostrar_arreglo(recorrido_c, N * N);

        cout << endl << "Arreglo D (recorrido en espiral invertido):" << endl;
        mostrar_arreglo(recorrido_d, N * N);

        cout << endl << "Elementos de C divisibles por los de D en la misma posicion:" << endl;
        for (int i = 0; i < N * N; i++) {
            if (*(recorrido_d + i) != 0 && *(recorrido_c + i) % *(recorrido_d + i) == 0) {
                cout << "Posicion " << i << ": " << *(recorrido_c + i) << " / " << *(recorrido_d + i) << " = " << *(recorrido_c + i) / *(recorrido_d + i) << endl;
            }
        }
    }
}

int main() {
    
    int opcion;
    cout << "Opciones disponibles:" << endl;
    cout << "1. Programa 1" << endl;
    cout << "2. Programa 2" << endl;
    cout << "3. Programa 3" << endl;
    cout << "0. Salir" << endl;
    cout << endl << "Ingrese la opcion: ";
    cin >> opcion;
    cout << endl;

    switch (opcion)
    {
        case 1:
            programa1();
            break;

        case 2:
            programa2();
            break;

        case 3:
            programa3();
            break;

        default:
            cout << "Ha decidido salir del programa." << endl;
            break;
    }


}