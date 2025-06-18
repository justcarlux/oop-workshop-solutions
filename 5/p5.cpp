#include <iostream>

using namespace std;

void mostrar_cola(char cola[], int numero_elementos) {
    if (numero_elementos == 0) {
        cout << endl << "La cola se ha quedado sin clientes" << endl << endl;
    }
    else {
        cout << endl << "La cola ha quedado de la siguiente manera: " << endl;
        for (int i = 0; i < numero_elementos; i++)
        {
            if (i == 0) {
                cout << "| ";
            }
            if (i == numero_elementos - 1) {
                cout << cola[i] << " |" << endl << endl;
            }
            else {
                cout << cola[i] << " | ";
            }
        }
    }
}

void cargar(char cola[], int numero_elementos) {
    for (int i = 0; i < numero_elementos; i++)
    {
        char elemento;
        cout << "Ingrese el cliente #" << (i + 1) << ": ";
        cin >> elemento;
        cola[i] = elemento;
    }
    mostrar_cola(cola, numero_elementos);
}

void atender(char cola[], int numero_elementos) {
    cout << "Se ha atendido el primer cliente de la cola: " << cola[0] << endl;
    for (int i = 1; i < numero_elementos + 1; i++)
    {
        cola[i - 1] = cola[i];
    }
    mostrar_cola(cola, numero_elementos);
}

void arribar(char cola[], int numero_elementos) {
    char elemento;
    cout << "Ingrese el cliente para colocar al final de la cola (en la posicion #" << (numero_elementos + 1) << "): ";
    cin >> elemento;
    cola[numero_elementos] = elemento;
    mostrar_cola(cola, numero_elementos + 1);
}

void ordenar(char cola[], int numero_elementos) {
    for (int i = 0; i < numero_elementos - 1; i++) {
        int indice_mas_pequeno = i;
        for (int j = i + 1; j < numero_elementos; j++) {
            if (cola[j] < cola[indice_mas_pequeno]) {
                indice_mas_pequeno = j;
            }
        }
        if (indice_mas_pequeno != i) {
            char aux = cola[i];
            cola[i] = cola[indice_mas_pequeno];
            cola[indice_mas_pequeno] = aux;
        }
    }
    cout << "La cola ha sido ordenada satisfactoriamente" << endl;
    mostrar_cola(cola, numero_elementos);
}

void desordenar(char cola[], int numero_elementos) {
    for (int i = 0; i < numero_elementos - 1; i++) {
        char aux = cola[i];
        cola[i] = cola[i + 1];
        cola[i + 1] = aux;
    }
    cout << "La cola ha sido desordenada satisfactoriamente" << endl;
    mostrar_cola(cola, numero_elementos);
}

bool es_vocal(char caracter) {
    return caracter == 'a' ||
        caracter == 'e' ||
        caracter == 'i' ||
        caracter == 'o' ||
        caracter == 'u' ||
        caracter == 'A' ||
        caracter == 'E' ||
        caracter == 'I' ||
        caracter == 'O' ||
        caracter == 'U';
}

void separar(char cola[], int numero_elementos) {
    int elementos_intercambiados = 0;
    for (int i = 0; i < numero_elementos; i++) {
        if (es_vocal(cola[i])) {
            char aux = cola[i];
            cola[i] = cola[elementos_intercambiados];
            cola[elementos_intercambiados] = aux;
            elementos_intercambiados++;
        }
    }
    cout << "La cola ha sido separada entre vocales y consonantes satisfactoriamente" << endl;
    mostrar_cola(cola, numero_elementos);
}

int main() {
	char cola[10];
    int cola_elementos = 0;

    while (true) {
        int opcion;
        cout << "Opciones disponibles:" << endl;
        cout << "(1) Cargar" << endl;
        cout << "(2) Atender" << endl;
        cout << "(3) Arribar" << endl;
        cout << "(4) Ordenar" << endl;
        cout << "(5) Desordenar" << endl;
        cout << "(6) Separar" << endl;
        cout << "(7) Terminar" << endl;
        cout << endl << "Ingrese la opcion: ";
        cin >> opcion;
        cout << endl;

        if (opcion == 1) {
            if (cola_elementos > 0) {
                char respuesta;
                cout << "Esta seguro que desea cargar nuevos clientes? La cola anterior se perdera (s/n): ";
                cin >> respuesta;
                if (respuesta != 's' && respuesta != 'S') {
                    cout << endl;
                    continue;
                }
            }
            int numero_elementos;
            cout << "Ingrese cuantos clientes desea cargar: ";
            cin >> numero_elementos;
            if (numero_elementos < 1) {
                cout << "Error: debe ingresar un valor mayor o igual a 1 de clientes" << endl << endl;
                continue;
            }
            if (numero_elementos > 10) {
                cout << "Error: no se pueden cargar tantos clientes" << endl << endl;
                continue;
            }
            cola_elementos = numero_elementos;
            cargar(cola, cola_elementos);
        }
        else if (opcion == 2) {
            if (cola_elementos < 1) {
                cout << "Error: la cola esta vacia" << endl << endl;
                continue;
            }
            cola_elementos--;
            atender(cola, cola_elementos);
        }
        else if (opcion == 3) {
            if (cola_elementos > 9) {
                cout << "Error: la cola esta llena" << endl << endl;
                continue;
            }
            arribar(cola, cola_elementos);
            cola_elementos++;
        }
        else if (opcion == 4) {
            if (cola_elementos < 1) {
                cout << "Error: la cola esta vacia" << endl << endl;
                continue;
            }
            ordenar(cola, cola_elementos);
        }
        else if (opcion == 5) {
            if (cola_elementos < 1) {
                cout << "Error: la cola esta vacia" << endl << endl;
                continue;
            }
            desordenar(cola, cola_elementos);
        }
        else if (opcion == 6) {
            if (cola_elementos < 1) {
                cout << "Error: la cola esta vacia" << endl << endl;
                continue;
            }
            separar(cola, cola_elementos);
        }
        else if (opcion == 7) {
            cout << "Ha decidido salir del programa." << endl;
            break;
        }
        else {
            cout << "Error: opcion desconocida" << endl << endl;
        }
    }

}