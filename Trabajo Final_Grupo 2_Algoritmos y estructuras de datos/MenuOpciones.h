#pragma once
#include "Recursos.h"

class MenuOpciones {

public:

	int mostrarMenu(string tipo, info datos) {

		string str = datos.nombre;

		transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
			return toupper(c);
			});

		if (tipo == "Cliente") {
			int op1;
			cout << "BIENVENIDO A LA APP SAPORE D'ITALIA, " << str << endl << endl;
			cout << "1. Crear Orden" << endl;
			cout << "2. Ver mis ordenes" << endl;
			cout << "3. Sistema de pagos" << endl;
			cout << "4. Informacion de cuenta " << endl;
			cout << "5. Volver al Logout" << endl << endl;
			cout << "Opcion: "; cin >> op1;

			return op1;
		}
		if (tipo == "Trabajador") {
			int op2;
			cout << "BIENVENIDO A LA APP SAPORE D'ITALIA" << endl << endl;
			cout << "1. Filtrar ordenes" << endl;
			cout << "2. Atender orden" << endl;
			cout << "3. Log out" << endl;
			cout << "Opcion: "; cin >> op2;

			return op2;
		}
	}

};