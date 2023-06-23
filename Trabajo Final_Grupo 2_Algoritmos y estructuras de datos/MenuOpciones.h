#pragma once
#include "Recursos.h"

class MenuOpciones {

public:

	int mostrarMenu(string tipo) {

		if (tipo == "Cliente") {
			int op1;
			cout << "BIENVENIDO A LA APP SAPORE D'ITALIA" << endl << endl;
			cout << "1. Crear Orden" << endl;
			cout << "2. Ver mis ordenes" << endl;
			cout << "3. Sistema de pagos" << endl;
			cout << "4. Volver al Logout" << endl << endl;
			cout << "Opcion: "; cin >> op1;

			return op1;
		}
		if (tipo == "Trabajador") {
			int op2;
			cout << "BIENVENIDO A LA APP SAPORE D'ITALIA" << endl << endl;
			cout << "1. Ver ordenes pendientes" << endl;
			cout << "2. Ver ordenes en preparacion" << endl;
			cout << "3. Ver ordenes listas" << endl;
			cout << "4. Ver ordenes entregadas" << endl;
			cout << "5. Ver ordenes canceladas" << endl;
			cout << "6. Volver al Logout" << endl << endl;
			cout << "Opcion: "; cin >> op2;

			return op2;
		}
	}

};