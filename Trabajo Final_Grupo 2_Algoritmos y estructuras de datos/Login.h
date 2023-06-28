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

    void iniciar();
    void CrearCuentaCliente(info& dato, HashTable<USCON, DCliente> &hash);
    void MostrarMenuCliente();
    //void MostrarMenuTrabajador(); //No tiene sentido que el trabajador se registre, solo que inicie sesion
    bool ValidaCliente(info& datos, HashTable<USCON, DCliente> &hash);
    bool ValidaTrabajador();
};

void Login::iniciar() {
    
}

void Login::CrearCuentaCliente(info & datos, HashTable<USCON, DCliente> &hash) {
        Registro registroCliente;

        registroCliente.LlenarFormulario(hash);

        ValidaCliente(datos, hash);
}

void Login::MostrarMenuCliente() {

    do {
        system("cls");
        cout << "BIENVENIDO CLIENTE " << endl << endl << "1. Iniciar sesion " << endl << "2. Registrarse \n\n" << "Opcion: ";
        cin >> RespuestaCliente;
    } while (RespuestaCliente < 1 || RespuestaCliente > 2);
}


bool Login::ValidaCliente(info &datos, HashTable<USCON, DCliente> &hash) {

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

        if (validarClientaso.validacionClientaso(nombreCliente, contraseñaCliente, datos, hash)) {
            return true;
        }
        else {
            return false;
        }
        break;

    case 2:
        system("cls");

        CrearCuentaCliente(datos, hash);

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