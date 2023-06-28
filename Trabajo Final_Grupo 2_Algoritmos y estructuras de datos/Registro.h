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
	void LlenarFormulario(HashTable<USCON, DCliente>& hash);

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
		archivo << contraseñaCliente1;
		archivo.close();
	}
	else {
		cout << "No se pudo abrir el archivo" << endl;
	}
}

void Registro::LlenarFormulario(HashTable<USCON, DCliente>& hash) {

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

	USCON y;
	y.usuario = DatosCliente.usuarioCliente;
	y.contrasena = DatosCliente.contraseniaCliente;
	escribir(DatosCliente.nombreCliente, DatosCliente.telefonoCliente, DatosCliente.direccionCliente, DatosCliente.usuarioCliente, DatosCliente.contraseniaCliente);
	hash.insert(y, DatosCliente);

	cout << "\n\nSe ha creado su cuenta exitosamente, ahora inicie sesion con su Usuario y Contrasenia" << endl;
	system("pause");

}


