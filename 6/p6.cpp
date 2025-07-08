#include <iostream>
#define MAX = 10;

using namespace std;

void mostrar_matriz(int matriz[10][10], int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void intercambiar_matrices(int matriz1[10][10], int matriz2[10][10], int n) {
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; j++) {
            if (i + 1 >= n) continue;
            int temp = matriz1[i][j];
            matriz1[i][j] = matriz2[j][i + 1];
            matriz2[j][i + 1] = temp;
        }
    }
}

bool esta_ordenado_asc(const int fila[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (fila[i] > fila[i + 1]) {
            return false;
        }
    }
    return true;
}

bool esta_ordenado_desc(const int fila[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (fila[i] < fila[i + 1]) {
            return false;
        }
    }
    return true;
}

void verificar_filas_ordenadas(int matriz[10][10], int n) {
    bool hayOrdenada = false;
    for (int i = 0; i < n; i++) {
        if (esta_ordenado_asc(matriz[i], n)) {
            cout << "La fila " << i << " de la segunda matriz esta ordenada ascendentemente" << endl;
            hayOrdenada = true;
        }
        else if (esta_ordenado_desc(matriz[i], n)) {
            cout << "La fila " << i << " de la segunda matriz esta ordenada descendentemente" << endl;
            hayOrdenada = true;
        }
    }
    if (!hayOrdenada) {
        cout << "Ninguna fila de la segunda matriz está ordenada" << endl;
    }
}

void buscar_submatriz(int matriz1[10][10], int n, int matriz2[10][10], int k, bool segunda) {
    bool encontrada = false;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= n - k; j++) {
            bool coincide = true;

            for (int x = 0; x < k && coincide; x++) {
                for (int y = 0; y < k && coincide; y++) {
                    if (matriz1[i + x][j + y] != matriz2[x][y]) {
                        coincide = false;
                    }
                }
            }

            if (coincide) {
                encontrada = true;
                cout << "La tercera matriz fue encontrada en la fila " << i << ", columna " << j << " de la " << (segunda ? "segunda" : "primera") << " matriz" << endl;
            }
        }
    }
    if (!encontrada) {
        cout << "La tercera matriz no se encuentra en la " << (segunda ? "segunda" : "primera") << " matriz" << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese N: ";
    cin >> n;

    if (n < 0) {
        cout << "El valor de N no puede ser menor que 0.";
    } else if (n > 10) {
        cout << "El valor de N no puede ser mayor a 10.";
    }
    else {
        int matriz1[10][10];
        int matriz2[10][10];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num;
                cout << "Ingrese el numero para fila " << i << ", columna " << j << " de la primera matriz: ";
                cin >> num;
                matriz1[i][j] = num;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num;
                cout << "Ingrese el numero para fila " << i << ", columna " << j << " de la segunda matriz: ";
                cin >> num;
                matriz2[i][j] = num;
            }
        }

        cout << endl;
        cout << "Primera matriz ingresada: " << endl;
        mostrar_matriz(matriz1, n);
        cout << endl;
        cout << "Segunda matriz ingresada: " << endl;
        mostrar_matriz(matriz2, n);
        cout << endl;
        intercambiar_matrices(matriz1, matriz2, n);
        cout << "Resultados despues de intercambiar las filas pares de la primera matriz con las columnas impares de la segunda:" << endl;
        cout << endl;
        cout << "Primera matriz:" << endl;
        mostrar_matriz(matriz1, n);
        cout << endl;
        cout << "Segunda matriz:" << endl;
        mostrar_matriz(matriz2, n);
        cout << endl;
        verificar_filas_ordenadas(matriz2, n);
        cout << endl;

        int k;
        cout << "Ingrese K: ";
        cin >> k;

        if (k < 0) {
            cout << "El valor de K no puede ser menor que 0.";
        }
        else if (k > n) {
            cout << "El valor de K no puede ser mayor a 10.";
        }
        else {
            int matriz3[10][10];
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    int num;
                    cout << "Ingrese el numero para fila " << i << ", columna " << j << " de la tercera matriz: ";
                    cin >> num;
                    matriz3[i][j] = num;
                }
            }
            cout << endl;
            cout << "Tercera matriz ingresada: " << endl;
            mostrar_matriz(matriz3, k);
            cout << endl;
            buscar_submatriz(matriz1, n, matriz3, k, false);
            buscar_submatriz(matriz2, n, matriz3, k, true);
        }

    }
}