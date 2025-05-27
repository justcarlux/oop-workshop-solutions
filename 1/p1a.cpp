#include <iostream>

using namespace std;

int main() {

	char codigo_tanque[50];
	cout << "Ingrese el codigo del tanque:" << endl;
	cin >> codigo_tanque;

	int capacidad_litros;
	cout << "Ingrese la capacidad en litros:" << endl;
	cin >> capacidad_litros;

	int hora_inicio;
	cout << "Ingrese la hora de inicio:" << endl;
	cin >> hora_inicio;

	int minutos_inicio;
	cout << "Ingrese los minutos de inicio:" << endl;
	cin >> minutos_inicio;

	char meridiano_inicio;
	cout << "Ingrese el meridiano de inicio:" << endl;
	cin >> meridiano_inicio;

	int hora_final;
	cout << "Ingrese la hora de finalizacion:" << endl;
	cin >> hora_final;

	int minutos_final;
	cout << "Ingrese los minutos de finalizacion:" << endl;
	cin >> minutos_final;

	char meridiano_final;
	cout << "Ingrese el meridiano de finalizacion:" << endl;
	cin >> meridiano_final;

	int total_minutos_inicio = hora_inicio * 60 + minutos_inicio + (
		meridiano_inicio == 'P' || meridiano_inicio == 'p' ? 12 * 60 : 0
	);
	int total_minutos_final = hora_final * 60 + minutos_final + (
		meridiano_final == 'P' || meridiano_final == 'p' ? 12 * 60 : 0
	);

	int total_minutos = total_minutos_final - total_minutos_inicio;
	int tiempo_llenado_horas = total_minutos / 60;
	int tiempo_llenado_minutos = total_minutos - (tiempo_llenado_horas * 60);

	total_minutos > 0 ?
    printf("\nTanque: %s\nCapacidad (litros): %d\nHora de inicio: %d:%d %s\nHora de finalizacion: %d:%d %s\nTiempo total de llenado: %d hora(s) y %d minuto(s)\nVelocidad (litros/minuto): %.2f\n",
           codigo_tanque,
           capacidad_litros,
           hora_inicio,
           minutos_inicio,
           meridiano_inicio == 'p' || meridiano_inicio == 'P' ? "P.M." : "A.M.",
           hora_final,
           minutos_final,
           meridiano_final == 'p' || meridiano_final == 'P' ? "P.M." : "A.M.",
           tiempo_llenado_horas,
           tiempo_llenado_minutos,
		   (float) capacidad_litros / (float) total_minutos) :
    printf("\nError de datos.\n");

}