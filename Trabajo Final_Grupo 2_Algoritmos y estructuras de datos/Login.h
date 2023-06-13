#pragma once
#include "Recursos.h"
#include "Registro.h"

class Login {
private:
public:
	Login() { }
	~Login() { }

	void CrearCuentaCliente();
	void ValidaCliente();
	void ValidaTrabajador();
};

void Login::CrearCuentaCliente() {
	Registro registroCliente;

	registroCliente.LlenarFormulario();

	ValidaCliente();
}

void Login::ValidaCliente() {
	int Respuesta;
	//ValidarCliente validarClientaso;

	string nombreCliente;
	string contraseñaCliente;

	cout << "Como cliente usted va a: " << endl << "Iniciar sesion (1)" << endl << "Registrarse(2)";
	cin >> Respuesta;

	switch (Respuesta) {
	case 1:
		cout << "Ingrese su Nombre de cliente: ";
		cin >> nombreCliente;

		cout << "Ingrese su Contraseña de cliente: ";
		cin >> contraseñaCliente;

		//ValidarClientaso.validar(nombreCliente, contraseñaCliente);
		break;
	case 2:
		CrearCuentaCliente();
		break;
	}

}

void Login::ValidaTrabajador() {
	string IDTrabajador, contraseñaTrabajador;
	//ValidarTrabajador validarTrabajadoraso;

	cout << "Ingrese su ID de trabajador: ";
	cin >> IDTrabajador;

	cout << "Ingrese su Contraseña de trabajador: ";
	cin >> contraseñaTrabajador;

	//validarTrabajadoraso(IDTrabajador, contraseñaTrabajador);
}