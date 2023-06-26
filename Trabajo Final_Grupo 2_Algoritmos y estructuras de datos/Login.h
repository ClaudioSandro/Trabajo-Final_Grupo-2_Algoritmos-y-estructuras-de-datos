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

    void CrearCuentaCliente(info& datos);
    void MostrarMenuCliente();
    //void MostrarMenuTrabajador(); //No tiene sentido que el trabajador se registre, solo que inicie sesion
    bool ValidaCliente(info& datos);
    bool ValidaTrabajador();
};

void Login::CrearCuentaCliente(info& datos) {
    Registro registroCliente;

    registroCliente.LlenarFormulario();

    ValidaCliente(datos);
}

void Login::MostrarMenuCliente() {

    do {
        system("cls");
        cout << "BIENVENIDO CLIENTE " << endl << endl << "1. Iniciar sesion " << endl << "2. Registrarse \n\n" << "Opcion: ";
        cin >> RespuestaCliente;
    } while (RespuestaCliente < 1 || RespuestaCliente > 2);
}


bool Login::ValidaCliente(info &datos) {

    ValidarCliente validarClientaso;

    string nombreCliente;
    string contraseñaCliente;


    MostrarMenuCliente();

    switch (RespuestaCliente) {
    case 1:
        system("cls");
        cout << "Ingrese usuario de cliente: ";
        cin >> nombreCliente;

        cout << "Ingrese su contrasenia de cliente: ";
        cin >> contraseñaCliente;

        if (validarClientaso.validacionClientaso(nombreCliente, contraseñaCliente, datos)) {
            return true;
        }
        else {
            return false;
        }
        break;

    case 2:
        system("cls");

        CrearCuentaCliente(datos);

        return true;
        break;
    }
}

bool Login::ValidaTrabajador() {
    string IDTrabajador, contraseñaTrabajador;
    ValidarTrabajador validarTrabajadoraso;

    system("cls"); 
    cout << "Ingrese su ID de trabajador: ";
    cin >> IDTrabajador;

    cout << "Ingrese su Contraseña de trabajador: ";
    cin >> contraseñaTrabajador;

    
    if (validarTrabajadoraso.validacionTrabajadoraso(IDTrabajador, contraseñaTrabajador)) {
        return true;
    }
    else {
        return false;
    }
}