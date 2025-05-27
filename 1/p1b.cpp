#include <iostream>

using namespace std;

int main() {

	cout << "Escriba el digito:" << endl;

	int numero;
	cin >> numero;
	numero = numero < 0 ? -numero : numero;
	
	// repetir 5 veces para el primer y último dígito
	// dado a que el rango máximo solo puede tener 5 dígitos
	int primer_digito = numero >= 10 ?
		numero / 10 :
		numero;
	primer_digito = primer_digito >= 10 ?
		primer_digito / 10 :
		primer_digito;
	primer_digito = primer_digito >= 10 ?
		primer_digito / 10 :
		primer_digito;
	primer_digito = primer_digito >= 10 ?
		primer_digito / 10 :
		primer_digito;
	primer_digito = primer_digito >= 10 ?
		primer_digito / 10 :
		primer_digito;

	int ultimo_digito = numero >= 10 ?
		numero % 10 :
		numero;
	ultimo_digito = numero >= 10 ?
		numero % 10 :
		numero;
	ultimo_digito = numero >= 10 ?
		numero % 10 :
		numero;
	ultimo_digito = numero >= 10 ?
		numero % 10 :
		numero;
	ultimo_digito = numero >= 10 ?
		numero % 10 :
		numero;

	cout << "Primer digito: " << primer_digito << endl;
	cout << "Ultimo digito: " << ultimo_digito << endl;

	cout << (primer_digito == ultimo_digito ? "El numero comienza y termina con el mismo digito" : "El numero no comianza y termina con el mismo digito") << endl;

}