#pragma once
#include "Recursos.h"

class ValidarTrabajador {
public:
	bool validacionTrabajadoraso(string IDTrabajador, string passwordTrabajador) { 

		ifstream archivo("Trabajador.txt");
		if (!archivo.is_open()) {
			cout << "Error al abrir el archivo" << endl;
			return false;
		}
		string line;

		while (getline(archivo, line)) {
			stringstream s(line);
			string IDTrabajador1, passwordTrabajador1;
			string aux;

			getline(s, aux, ',');
			IDTrabajador1 = aux;
			getline(s, aux, ',');
			passwordTrabajador1 = aux;

			if (IDTrabajador1 == IDTrabajador && passwordTrabajador1 == passwordTrabajador) {
				system("cls");
				cout << "INICIO DE SESION CORRECTO" << endl;
				cout << "Bienvenido " << IDTrabajador << endl << endl;
				system("pause");
				return true;
			}
		}
		cout << "ID y/o contrasenia incorrectos" << endl;
		return false;
	}
};