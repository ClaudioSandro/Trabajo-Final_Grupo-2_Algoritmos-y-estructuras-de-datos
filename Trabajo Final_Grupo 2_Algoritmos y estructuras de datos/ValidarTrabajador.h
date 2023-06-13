#pragma once
#include "Recursos.h"

class ValidarTrabajador {
public:
	void leer() {

		ifstream archivo("Trabajador.txt");
		if (!archivo.is_open()) {
			cout << "Error al abrir el archivo" << endl;
		}
		string line;

		while (getline(archivo, line)) {
			stringstream s(line);
			string IDTrabajador, passwordTrabajador;
			string aux;

			getline(s, aux, ',');
			IDTrabajador = aux;
			getline(s, aux, ',');
			passwordTrabajador = aux;
		}
	}
};