#include <iostream>

using namespace std;

int tiempo_diferencia(int horas_llegada, int minutos_llegada, int horas_salida, int minutos_salida) {
    int llegada_total = horas_llegada * 60 + minutos_llegada;
    int salida_total = horas_salida * 60 + minutos_salida;
    return salida_total - llegada_total;
}

void imprimir_duracion(int diferencia) {
	int horas = diferencia / 60;
	int minutos = diferencia - (horas * 60);
	if (minutos == 0) {
		cout << " | Duracion: " << horas << " hora(s)" << endl;
	} else if (horas == 0) { 
		cout << " | Duracion: " << minutos << " minuto(s)" << endl;
	} else {
		cout << " | Duracion: " << horas << " hora(s) y " << minutos << " minuto(s)" << endl;
	}
}

void mostrar_usuarios_cola_gasolina(int cantidad_vehiculos, char placas[][100], int horas_llegada[], int minutos_llegada[], int horas_salida[], int minutos_salida[]) {
	int diferencia_menor = -1;
	for (int i = 0; i < cantidad_vehiculos; i++) {
		int hora_llegada = horas_llegada[i];
		int minuto_llegada = minutos_llegada[i];
		int hora_salida = horas_salida[i];
		int minuto_salida = minutos_salida[i];
		int diferencia = tiempo_diferencia(hora_llegada, minuto_llegada, hora_salida, minuto_salida);
		if (diferencia_menor == -1 || diferencia < diferencia_menor) {
			diferencia_menor = diferencia;
		}
		cout << (i + 1) << ". Placa: " << placas[i] << 
			" | Hora de llegada: " << (hora_llegada < 9 ? "0" : "") << hora_llegada << ":" << (minuto_llegada < 9 ? "0" : "") << minuto_llegada <<
			" | Hora de salida: " << (hora_salida < 9 ? "0" : "") << hora_salida << ":" << (minuto_salida < 9 ? "0" : "") << minuto_salida;
			imprimir_duracion(diferencia);
	}
	
	for (int i = 0; i < cantidad_vehiculos; i++) {
		int hora_llegada = horas_llegada[i];
		int minuto_llegada = minutos_llegada[i];
		int hora_salida = horas_salida[i];
		int minuto_salida = minutos_salida[i];
		int diferencia = tiempo_diferencia(hora_llegada, minuto_llegada, hora_salida, minuto_salida);
		if (diferencia == diferencia_menor) {
			cout << endl << "Vehiculo que fue atendido mas rapido: " << endl;
			cout << (i + 1) << ". Placa: " << placas[i] << 
			" | Hora de llegada: " << (hora_llegada < 9 ? "0" : "") << hora_llegada << ":" << (minuto_llegada < 9 ? "0" : "") << minuto_llegada <<
			" | Hora de salida: " << (hora_salida < 9 ? "0" : "") << hora_salida << ":" << (minuto_salida < 9 ? "0" : "") << minuto_salida;
			imprimir_duracion(diferencia);
			break;
		}
	}
}

int participante_signo_zodiacal(int dia_nacimiento, int mes_nacimiento) {
    if ((mes_nacimiento == 3 && dia_nacimiento >= 21) || (mes_nacimiento == 4 && dia_nacimiento <= 21)) {
        return 1;
    }
    else if ((mes_nacimiento == 4 && dia_nacimiento >= 22) || (mes_nacimiento == 5 && dia_nacimiento <= 20)) {
        return 2;
    }
    else if ((mes_nacimiento == 5 && dia_nacimiento >= 21) || (mes_nacimiento == 6 && dia_nacimiento <= 20)) {
        return 3;
    }
    else if ((mes_nacimiento == 6 && dia_nacimiento >= 21) || (mes_nacimiento == 7 && dia_nacimiento <= 20)) {
        return 4;
    }
    else if ((mes_nacimiento == 7 && dia_nacimiento >= 21) || (mes_nacimiento == 8 && dia_nacimiento <= 22)) {
        return 5;
    }
    else if ((mes_nacimiento == 8 && dia_nacimiento >= 23) || (mes_nacimiento == 9 && dia_nacimiento <= 22)) {
        return 6;
    }
    else if ((mes_nacimiento == 9 && dia_nacimiento >= 23) || (mes_nacimiento == 10 && dia_nacimiento <= 22)) {
        return 7;
    }
    else if ((mes_nacimiento == 10 && dia_nacimiento >= 23) || (mes_nacimiento == 11 && dia_nacimiento <= 22)) {
        return 8;
    }
    else if ((mes_nacimiento == 11 && dia_nacimiento >= 23) || (mes_nacimiento == 12 && dia_nacimiento <= 21)) {
        return 9;
    }
    else if ((mes_nacimiento == 12 && dia_nacimiento >= 22) || (mes_nacimiento == 1 && dia_nacimiento <= 21)) {
        return 10;
    }
    else if ((mes_nacimiento == 1 && dia_nacimiento >= 22) || (mes_nacimiento == 2 && dia_nacimiento <= 21)) {
        return 11;
    }
    else if ((mes_nacimiento == 2 && dia_nacimiento >= 22) || (mes_nacimiento == 3 && dia_nacimiento <= 20)) {
        return 12;
    }
    else {
        return 0;
    }
}

int imprimir_signo_zodiacal(int signo_zodiacal) {
	switch (signo_zodiacal) {
		case 1: {
			cout << "Aries";
			break;
		}
        case 2: {
        	cout << "Tauro";
			break;
		}
        case 3: {
        	cout << "Geminis";
			break;
		}
        case 4: {
        	cout << "Cancer";
        	break;
		}
		case 5: {
			cout << "Leo";
			break;
		}
		case 6: {
			cout << "Virgo";
			break;
		}
		case 7: {
			cout << "Libra";
			break;
		}
		case 8: {
			cout << "Escorpio";
			break;
		}
		case 9: {
			cout << "Sagitario";
			break;
		}
		case 10: {
			cout << "Capricornio";
			break;
		}
		case 11: {
			cout << "Acuario";
			break;
		}
		case 12: {
			cout << "Piscis";
			break;
		}
	}
}

int main() {

    int opcion;
    cout << "Opciones disponibles:" << endl;
    cout << "(1) Cola de gasolina" << endl;
    cout << "(2) Zodiaco" << endl;
    cout << "(3) Salir" << endl;
    cout << endl << "Ingrese la opcion: ";
    cin >> opcion;
    cout << endl;

    if (opcion == 1) {
        cout << "Ingrese la cantidad de vehiculos: ";
        int cantidad_vehiculos;
        cin >> cantidad_vehiculos;
        if (cantidad_vehiculos > 0) {
        	char placas[cantidad_vehiculos][100];
	        int horas_llegada[cantidad_vehiculos];
	        int minutos_llegada[cantidad_vehiculos];
	        int horas_salida[cantidad_vehiculos];
	        int minutos_salida[cantidad_vehiculos];
	        bool invalido = false;
	        for (int i = 0; i < cantidad_vehiculos; i++) {
	            cout << "Ingrese la placa para el vehiculo " << (i + 1) << ": ";
	            cin >> placas[i];
	            cout << "Ingrese la hora de llegada para el vehiculo " << (i + 1) << ": ";
	            cin >> horas_llegada[i];
	            if (horas_llegada[i] < 0 || horas_llegada[i] > 23) {
	            	invalido = true;
	            	cout << "Hora de llegada especificada para el vehiculo " << (i + 1) << " invalida.";
	            	break;
				}
	            cout << "Ingrese los minutos de llegada para el vehiculo " << (i + 1) << ": ";
	            cin >> minutos_llegada[i];
	            if (minutos_llegada[i] < 0 || minutos_llegada[i] > 59) {
	            	invalido = true;
	            	cout << "Minutos de llegada especificados para el vehiculo " << (i + 1) << " invalidos.";
	            	break;
				}
	            cout << "Ingrese la hora de salida para el vehiculo " << (i + 1) << ": ";
	            cin >> horas_salida[i];
	            if (horas_salida[i] < 0 || horas_salida[i] > 23) {
	            	invalido = true;
	            	cout << "Hora de llegada especificada para el vehiculo " << (i + 1) << " invalida.";
	            	break;
				}
	            cout << "Ingrese los minutos de salida para el vehiculo " << (i + 1) << ": ";
	            cin >> minutos_salida[i];
				if (minutos_salida[i] < 0 || minutos_salida[i] > 59) {
	            	invalido = true;
	            	cout << "Minuto de llegada especificados para el vehiculo " << (i + 1) << " invalidos.";
	            	break;
				}
				int diferencia = tiempo_diferencia(horas_llegada[i], minutos_llegada[i], horas_salida[i], minutos_salida[i]);
				if (diferencia == 0) {
					invalido = true;
	            	cout << "Tiempos de llegada y salida para el vehiculo " << (i + 1) << " invalidos, son iguales.";
	            	break;
				}
				if (diferencia < 0) {
					invalido = true;
	            	cout << "Tiempos de llegada y salida para el vehiculo " << (i + 1) << " invalidos, la hora de salida ocurre primero que la hora de llegada.";
	            	break;
				}
	        }
	        if (invalido == false) {
				cout << endl;
				mostrar_usuarios_cola_gasolina(cantidad_vehiculos, placas, horas_llegada, minutos_llegada, horas_salida, minutos_salida);
			}
		} else {
			cout << "Cantidad de vehiculos invalida.";
		}
    }
    else if (opcion == 2) {
        char nombres[999][300];
        char sexos[999];
        int edades[999];
        int dias_nacimiento[999];
        int meses_nacimiento[999];
        int i = -1;
        while (i < 998) {
        	i++;
        	cout << "Ingrese el nombre del participante " << (i + 1) << ": ";
	        cin >> nombres[i];
	        cout << "Ingrese el sexo del participante " << (i + 1) << " (M/F): ";
	        cin >> sexos[i];
	        if (sexos[i] != 'm' && sexos[i] != 'M' && sexos[i] != 'f' && sexos[i] != 'F') {
	            cout << "Sexo del participante " << (i + 1) << " invalido";
	            break; 
			}
	        cout << "Ingrese la edad del participante " << (i + 1) << ": ";
	        cin >> edades[i];
	        if (edades[i] < 0) {
	            cout << "Edad del participante " << (i + 1) << " invalida";
	            break; 
			}
	        cout << "Ingrese el dia de nacimiento del participante " << (i + 1) << " (1/31): ";
	        cin >> dias_nacimiento[i];
	        if (dias_nacimiento[i] < 1 || dias_nacimiento[i] > 31) {
	           	cout << "Dia de nacimiento del participante " << (i + 1) << " invalido";
	           	break; 
			}
			cout << "Ingrese el mes de nacimiento del participante " << (i + 1) << " (1/12): ";
	        cin >> meses_nacimiento[i];
			if (meses_nacimiento[i] < 1 || meses_nacimiento[i] > 12) {
	           	cout << "Mes de nacimiento del participante " << (i + 1) << " invalido";
	           	break;
			}
			if (participante_signo_zodiacal(dias_nacimiento[i], meses_nacimiento[i]) == 0) {
	           	cout << "Fecha de nacimiento del participante " << (i + 1) << " invalida, no se pudo encontrar signo zodiacal";
	           	break;
			}
			
			cout << endl << "Participantes registrados (organizados por signo zodiacal): " << endl;
			for (int j = 0; j < 12; j++) {
				int signo_actual = j + 1;
				for (int k = 0; k < i + 1; k++) {
					int signo_zodiacal = participante_signo_zodiacal(dias_nacimiento[k], meses_nacimiento[k]);
					if (signo_zodiacal == signo_actual) {
						int dia_nacimiento = dias_nacimiento[k];
						int mes_nacimiento = meses_nacimiento[k];
						cout << "Participante #" << (k + 1) << " | ";
						imprimir_signo_zodiacal(signo_zodiacal);
						cout << " | Nombre: " << nombres[k] <<
							" | Sexo: " << (sexos[k] == 'm' || sexos[k] == 'M' ? "masculino" : "femenino") <<
							" | Edad: " << edades[k] << 
							" | Mes de nacimiento: " << (dia_nacimiento < 9 ? "0" : "") << dia_nacimiento << "/" << (mes_nacimiento < 9 ? "0" : "") << mes_nacimiento
							<< endl;
					}
				}					
			}
			
			cout << endl;
			
			int total_mujeres_sagitario = 0;
			int mujeres_sagitario_edades = 0;
			for (int j = 0; j < i + 1; j++) {
			    int signo_zodiacal = participante_signo_zodiacal(dias_nacimiento[j], meses_nacimiento[j]);
			    if (signo_zodiacal == 9 && (sexos[j] == 'f' || sexos[j] == 'F')) {
			        total_mujeres_sagitario++;
			        mujeres_sagitario_edades += edades[j];
			    }
			}
			printf(
				"Edad promedio de las participantes femeninas Sagitario: %.2f\n",
				total_mujeres_sagitario == 0 ? 0 : (float) mujeres_sagitario_edades / (float) total_mujeres_sagitario
			);
			
			int total_mujeres_geminis = 0;
			int mujeres_geminis_edades = 0;
			for (int j = 0; j < i + 1; j++) {
			    int signo_zodiacal = participante_signo_zodiacal(dias_nacimiento[j], meses_nacimiento[j]);
			    if (signo_zodiacal == 3 && (sexos[j] == 'f' || sexos[j] == 'F')) {
			        total_mujeres_geminis++;
			        mujeres_geminis_edades += edades[j];
			    }
			}
			printf(
				"Edad promedio de las participantes femeninas Geminis: %.2f\n",
				total_mujeres_geminis == 0 ? 0 : (float) mujeres_geminis_edades / (float) total_mujeres_geminis
			);
			
			int total_mujeres_geminis_y_sagitario = 0;
			int mujeres_geminis_y_sagitario_edades = 0;
			for (int j = 0; j < i + 1; j++) {
			    int signo_zodiacal = participante_signo_zodiacal(dias_nacimiento[j], meses_nacimiento[j]);
			    if ((signo_zodiacal == 3 || signo_zodiacal == 9) && (sexos[j] == 'f' || sexos[j] == 'F')) {
			        total_mujeres_geminis_y_sagitario++;
			        mujeres_geminis_y_sagitario_edades += edades[j];
			    }
			}
			printf(
			    "Edad promedio de las participantes femeninas Geminis y Sagitario: %.2f\n",
			    total_mujeres_geminis_y_sagitario == 0 ? 0 : (float) mujeres_geminis_y_sagitario_edades / (float) total_mujeres_geminis_y_sagitario
			);
			
			int personas_leo = 0;
			for (int j = 0; j < i + 1; j++) {
				int signo_zodiacal = participante_signo_zodiacal(dias_nacimiento[j], meses_nacimiento[j]);
				if (signo_zodiacal == 5) {
					personas_leo++;	
				}
			}
			cout << "Cantidad de personas Leo: " << personas_leo << endl << endl;
			
			cout << "Desea finalizar con la ejecucion de este programa? (S/N): ";
			char respuesta;
			cin >> respuesta;
			if (respuesta == 's' || respuesta == 'S') {
				break;
			}
			cout << endl;
		}
    }
    else {
        cout << "Ha decidido salir del programa." << endl;
    }

}