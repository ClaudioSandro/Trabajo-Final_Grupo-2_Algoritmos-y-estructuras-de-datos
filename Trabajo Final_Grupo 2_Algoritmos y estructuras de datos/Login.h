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
	string contrase�aCliente;

	cout << "Como cliente usted va a: " << endl << "Iniciar sesion (1)" << endl << "Registrarse(2)";
	cin >> Respuesta;

	switch (Respuesta) {
	case 1:
		cout << "Ingrese su Nombre de cliente: ";
		cin >> nombreCliente;

		cout << "Ingrese su Contrase�a de cliente: ";
		cin >> contrase�aCliente;

		//ValidarClientaso.validar(nombreCliente, contrase�aCliente);
		break;
	case 2:
		CrearCuentaCliente();
		break;
	}

}

void Login::ValidaTrabajador() {
	string IDTrabajador, contrase�aTrabajador;
	//ValidarTrabajador validarTrabajadoraso;

	cout << "Ingrese su ID de trabajador: ";
	cin >> IDTrabajador;

	cout << "Ingrese su Contrase�a de trabajador: ";
	cin >> contrase�aTrabajador;

	//validarTrabajadoraso(IDTrabajador, contrase�aTrabajador);
}