#pragma once
#include "Recursos.h"
#include "Registro.h"
#include "ValidarCliente.h"

class Login {
private:
    int Respuesta;
public:
	Login() { }
	~Login() { }

	void CrearCuentaCliente();
    void MostrarMenuCliente();
	bool ValidaCliente();
	void ValidaTrabajador();
};

void Login::CrearCuentaCliente() {
	Registro registroCliente;

	registroCliente.LlenarFormulario();

	ValidaCliente();
}

void Login::MostrarMenuCliente() {
    
    do {
        system("cls");
        cout << "Como cliente voy a... " << endl << "1. Iniciar sesion " << endl << "2. Registrarse \n\n" << "Opcion: ";
        cin >> Respuesta;
    } while (Respuesta < 1 || Respuesta > 2);
}

bool Login::ValidaCliente() {
    
    ValidarCliente validarClientaso;

    string nombreCliente;
    string contrase�aCliente;

    
    MostrarMenuCliente();

    if (Respuesta == 1) {
        system("cls");
        cout << "Ingrese su Nombre de cliente: ";
        cin >> nombreCliente;

        cout << "Ingrese su Contrasenia de cliente: ";
        cin >> contrase�aCliente;

        if (validarClientaso.validacion(nombreCliente, contrase�aCliente)) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        // Manejar la opci�n de registrarse aqu� o devolver un valor adecuado
        return false;
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