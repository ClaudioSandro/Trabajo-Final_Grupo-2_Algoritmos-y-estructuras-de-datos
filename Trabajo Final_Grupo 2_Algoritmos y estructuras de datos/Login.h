#pragma once
#include "Recursos.h"
#include "Registro.h"
#include "ValidarCliente.h"
#include "ValidarTrabajador.h"

class Login {
private:
    int RespuestaCliente; 
    int RespuestaTrabajador; 
public:
    Login() { }
    ~Login() { }

    void CrearCuentaCliente();
    void MostrarMenuCliente();
    //void MostrarMenuTrabajador(); //No tiene sentido que el trabajador se registre, solo que inicie sesion
    bool ValidaCliente();
    bool ValidaTrabajador();
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
        cin >> RespuestaCliente;
    } while (RespuestaCliente < 1 || RespuestaCliente > 2);
}


bool Login::ValidaCliente() {

    ValidarCliente validarClientaso;

    string nombreCliente;
    string contrase�aCliente;


    MostrarMenuCliente();

    switch (RespuestaCliente) {
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

bool Login::ValidaTrabajador() {
    string IDTrabajador, contrase�aTrabajador;
    ValidarTrabajador validarTrabajadoraso;

    system("cls"); 
    cout << "Ingrese su ID de trabajador: ";
    cin >> IDTrabajador;

    cout << "Ingrese su Contrase�a de trabajador: ";
    cin >> contrase�aTrabajador;

    
    if (validarTrabajadoraso.validacionTrabajadoraso(IDTrabajador, contrase�aTrabajador)) {
        return true;
    }
    else {
        return false;
    }
}