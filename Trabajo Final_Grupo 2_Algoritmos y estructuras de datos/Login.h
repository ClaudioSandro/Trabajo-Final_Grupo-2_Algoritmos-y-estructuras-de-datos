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

    switch (Respuesta) {
    case 1:
        system("cls");
        cout << "Ingrese su Nombre de cliente: ";
        cin >> nombreCliente;

        cout << "Ingrese su Contrasenia de cliente: ";
        cin >> contrase�aCliente;

        if (validarClientaso.validacionClientaso(nombreCliente, contrase�aCliente)) {
            return true;
        }
        else {
            return false;
        }
        break;

    case 2:
        system("cls");

        CrearCuentaCliente();

        return true;
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