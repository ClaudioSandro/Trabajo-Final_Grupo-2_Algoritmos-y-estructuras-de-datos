#pragma once
#include "Recursos.h"


class ValidarCliente
{
public:
	bool validacion(string userCliente, string passwordCliente) {
		ifstream archivo("Cliente.txt");
		if (!archivo.is_open()) {
			cout << "Error al abrir el archivo" << endl;
			return false;
		}

		string line;
		while (getline(archivo, line)) {
			stringstream s(line);
			string userCliente1, passwordCliente1;
			string aux;

			getline(s, aux, ',');
			userCliente1 = aux;
			getline(s, aux, ',');
			passwordCliente1 = aux;

			if (userCliente == userCliente1 && passwordCliente == passwordCliente1) {
				system("cls");
				cout << "INICIO DE SESION CORRECTO" << endl;
				cout << "Bienvenido " << userCliente << endl << endl;
				return true;
			}
		}

		cout << "Usuario o contrasenia incorrectos" << endl;
		return false;
	}
};
