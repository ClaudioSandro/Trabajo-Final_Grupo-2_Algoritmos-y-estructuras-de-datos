#pragma once
#include "MenuOpciones.h"
#include "SistemaPagos.h"
#include "SistemaOrdenes.h"
#include "Login.h"


class Sesion {

private:
    MenuOpciones menu;
    Cliente usuarioCliente;
    //Trabajador usuarioTrabajador
    Login loginSesion;
    string tipoCuenta = "Cliente";
public:

    //get-set
    string getTipoCuenta() { return tipoCuenta; }
    void setTipoCuenta(string _tipoCuenta) { tipoCuenta = _tipoCuenta; }

    //principales
    void iniciarSesion();
    void menuPrincipal();
    void sistemaOrdenes();
    void sistemaPagos();

};

void Sesion::iniciarSesion() {

    string tipo;
    tipo = "Cliente"; //Este dato se obtiene del proceso de login

    if (tipo == "Cliente") {
        //Pasar los datos de usuario cliente
    }
    if (tipo == "Trabajador") {
        //Pasar los datos de usuario trabajador
    }
    int opcionSesion;
    do {

        cout << "BIENVENIDO A LA APP SAPORE D'ITALIA" << endl << endl;
        cout << "1. Soy Cliente" << endl;
        cout << "2. Soy Trabajador" << endl;
        cout << "3. Salir" << endl << endl;
        cout << "Opcion: ";
        cin >> opcionSesion;

    } while (opcionSesion < 1 || opcionSesion > 3);

    switch (opcionSesion) {
    case 1:
        system("cls");
        loginSesion.ValidaCliente();
        menuPrincipal();
        break;
    case 2:
        system("cls");
        loginSesion.ValidaTrabajador();
        break;
    case 3: exit(0);
    }
}

void Sesion::menuPrincipal() {

    string tipoCuenta = getTipoCuenta(); //Esto se obtiene del sistema de validacion de cuenta

    if (tipoCuenta == "Cliente") {
        int op = menu.mostrarMenu("Cliente");
        system("cls");
        switch (op) {
        case 1: sistemaOrdenes(); break;
        case 3: sistemaPagos(); break;
        case 4: exit(0);
        }
    }

    //Lo mismo para trabajador
}

void Sesion::sistemaPagos() {
    SistemaPagos pagos;
    bool continuar = true;

    do {
        int op = pagos.menuPagos();
        switch (op)
        {
        case 1:pagos.pagar(usuarioCliente); break;
        case 2:pagos.mostrarTarjeta(usuarioCliente); break;
        case 3:usuarioCliente.nuevaTarjeta(); break;
        case 4:pagos.eliminarTarjeta(usuarioCliente); break;
        case 5:continuar = false;  break;
        }
    } while (continuar);
}

void Sesion::sistemaOrdenes() {
    SistemaOrdenes ordenes;
    int op_ordenes;

    do {
        op_ordenes = ordenes.menuSistemaOrdenes();
        switch (op_ordenes)
        {
        case 1: ordenes.agregar(); break;
        case 2: ordenes.eliminar(); break;
        case 3: ordenes.mostrarOrden(); break;
        case 4: ordenes.confirmar(); break;
        }
    } while (op_ordenes != 5);

 
}

