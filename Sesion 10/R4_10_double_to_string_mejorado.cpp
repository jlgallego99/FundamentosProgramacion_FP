//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////
	
// Double to string mejorado

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double PotenciaEntera (double base, int exponente){
	double potencia;
	
	potencia = 1;
	for (int i = 0 ; i < exponente; i++){
		potencia = base * potencia;
	}
	
	return potencia;
}

double Redondea (double numero_real, int redondear){
	const int BASE10 = 10;
	double potencia, redondeo, numero_redondeado;
	
	potencia = numero_real * PotenciaEntera (BASE10, redondear);																			
	redondeo = round(potencia);																						
	numero_redondeado = redondeo / PotenciaEntera (BASE10, redondear);
	
	return numero_redondeado;
}

string EliminaUltimos (string cadena, char a_borrar){
	int i;
	
	i = cadena.size () - 1;
	while (cadena[i] == a_borrar){
		cadena.pop_back ();
		i--;
	}
	
	return cadena;
}

string DoubleToString (double numero_real, int redondear){
	double numero_redondeado;
	string numero_redondeado_cadena;
	const char A_BORRAR = '0', PUNTO_DECIMAL = '.';
	char convertir_char;
	const int BASE10 = 10;
	int parte_entera, parte_decimal;
	
	numero_redondeado = Redondea (numero_real, redondear);
	
	parte_entera = numero_redondeado / 1;
	convertir_char = parte_entera + A_BORRAR;
	numero_redondeado_cadena.push_back (convertir_char);
	numero_redondeado_cadena.push_back (PUNTO_DECIMAL);
	numero_redondeado = numero_redondeado - parte_entera;
	numero_redondeado = Redondea (numero_redondeado, redondear);
	
	for (int i = 0 ; i < redondear ; i++){
		numero_redondeado = numero_redondeado * BASE10;
		parte_decimal = numero_redondeado / 1;
		convertir_char = parte_decimal + A_BORRAR;
		numero_redondeado_cadena.push_back (convertir_char);
		numero_redondeado = numero_redondeado - parte_decimal;
	}

	numero_redondeado_cadena = EliminaUltimos (numero_redondeado_cadena, A_BORRAR);

	return numero_redondeado_cadena;
}

int main (){
	cout.precision(10);
	double numero_real;
	int redondear;
	string numero_redondeado;
	
	cout << "�N�mero real que quiere aproximar? ";
	cin >> numero_real;
	cout << "�A cu�ntas cifras decimales? ";
	cin >> redondear;
	
	numero_redondeado = DoubleToString (numero_real, redondear);
	
	cout << "\nEl n�mero redondeado como cadena de caracteres es: "
		  << numero_redondeado;
	
}
