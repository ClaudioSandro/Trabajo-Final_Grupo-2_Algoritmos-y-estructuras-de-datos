#pragma once
#include "Recursos.h"
#include <fstream>
#include <string>
#include <iostream>

class Registro {
private:
	DCliente DatosCliente;
public:
	Registro() {
		DatosCliente.nombreCliente = "";
		DatosCliente.telefonoCliente = "";
		DatosCliente.direccionCliente = "";
		DatosCliente.usuarioCliente = "";
		DatosCliente.contraseniaCliente = "";
	}
	~Registro() { }

	void escribir(string nombreCliente1, string telefonoCliente1, string direccionCliente1, string usuarioCliente1, string contraseñaCliente1);
	void LlenarFormulario();

};

void Registro::escribir(string nombreCliente1, string telefonoCliente1, string direccionCliente1, string usuarioCliente1, string contraseñaCliente1) {
	ofstream archivo;
	archivo.open("Cliente.txt", ios::app);
	if (archivo.is_open())
	{
		archivo << nombreCliente1 << ",";
		archivo << telefonoCliente1 << ",";
		archivo << direccionCliente1 << ",";
		archivo << usuarioCliente1 << ",";
		archivo << contraseñaCliente1 << endl;
		archivo.close();
	}
	else {
		cout << "No se pudo abrir el archivo" << endl;
	}
}

void Registro::LlenarFormulario() {

	getline(cin, DatosCliente.nombreCliente);
	cout << "Ingrese su Nombre: ";
	getline(cin, DatosCliente.nombreCliente);

	cout << "Ingrese su Telefono: ";
	getline(cin, DatosCliente.telefonoCliente);

	cout << "Ingrese su Direccion: ";
	getline(cin, DatosCliente.direccionCliente);

	cout << "Ingrese su Usuario: ";
	getline(cin, DatosCliente.usuarioCliente);

	cout << "Ingrese su Contraseña: ";
	getline(cin, DatosCliente.contraseniaCliente);

	escribir(DatosCliente.nombreCliente, DatosCliente.telefonoCliente, DatosCliente.direccionCliente, DatosCliente.usuarioCliente, DatosCliente.contraseniaCliente);

	cout << "\n\nSe ha creado su cuenta exitosamente, ahora inicie sesion con su Usuario y Contrasenia" << endl;
	system("pause");

}


