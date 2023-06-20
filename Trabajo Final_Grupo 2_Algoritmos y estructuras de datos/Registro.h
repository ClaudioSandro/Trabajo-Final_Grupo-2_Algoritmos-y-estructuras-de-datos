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
		DatosCliente.contrase�aCliente = "";
	}
	~Registro() { }

	void escribir(string nombreCliente1, string telefonoCliente1, string direccionCliente1, string usuarioCliente1, string contrase�aCliente1);
	void LlenarFormulario();

};

void Registro::escribir(string nombreCliente1, string telefonoCliente1, string direccionCliente1, string usuarioCliente1, string contrase�aCliente1) {
	ofstream archivo;
	archivo.open("Clientes.txt", ios::out);
	if (archivo.is_open())
	{
		archivo << nombreCliente1 << ",";
		archivo << telefonoCliente1 << ",";
		archivo << direccionCliente1 << ",";
		archivo << usuarioCliente1 << ",";
		archivo << contrase�aCliente1 << endl;
		archivo.close();
	}
	else {
		cout << "No se pudo abrir el archivo" << endl;
	}
}

void Registro::LlenarFormulario() {

	cout << "Ingrese su Nombre: ";
	cin >> DatosCliente.nombreCliente;

	cout << "Ingrese su Telefono: ";
	cin >> DatosCliente.telefonoCliente;

	cout << "Ingrese su Direccion: ";
	cin >> DatosCliente.direccionCliente;

	cout << "Ingrese su Usuario: ";
	cin >> DatosCliente.usuarioCliente;

	cout << "Ingrese su Contrase�a: ";
	cin >> DatosCliente.contrase�aCliente;

	escribir(DatosCliente.nombreCliente, DatosCliente.telefonoCliente, DatosCliente.direccionCliente, DatosCliente.usuarioCliente, DatosCliente.contrase�aCliente);
}

