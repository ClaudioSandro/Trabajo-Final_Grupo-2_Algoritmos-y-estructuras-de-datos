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
    string tipoCuenta = "";
    vector<Boleta*> boletas;

public:

    //get-set
    string getTipoCuenta() { return tipoCuenta; }
    void setTipoCuenta(string _tipoCuenta) { tipoCuenta = _tipoCuenta; }

    //principales
    void iniciarSesion();
    int menuPrincipal();
    void sistemaOrdenes();
    void sistemaPagos();

};

void Sesion::iniciarSesion() {
    Login loginSesion;

    int opcionSesion;
    do {
        system("cls");
        cout << "BIENVENIDO A LA APP SAPORE D'ITALIA" << endl << endl;
        cout << "1. Login like Cliente" << endl;
        cout << "2. Login like Trabajador" << endl;
        cout << "3. Salir de Sapore D' Italia" << endl << endl;
        cout << "Opcion: ";
        cin >> opcionSesion;

        switch (opcionSesion) {
        case 1:
            if (loginSesion.ValidaCliente() == true) {
                system("cls");
                setTipoCuenta("Cliente");
                int op;
                do {
                    op = menuPrincipal();
                } while (op!= 4);
                
            }
            else {
                cout << "No se pudo iniciar sesion" << endl;
            }
            break;
        case 2:
            if (loginSesion.ValidaTrabajador() == true) {
                system("cls");
                setTipoCuenta("Trabajador");
                menuPrincipal(); 
            }
            else {
                cout << "No se pudo iniciar sesion" << endl;
            }
            break;
        case 3:
            exit(0);
        }

    } while (opcionSesion < 1 || opcionSesion > 3);


}

int Sesion::menuPrincipal() {

    string tipoCuenta = getTipoCuenta(); //Esto se obtiene del sistema de validacion de cuenta

    if (tipoCuenta == "Cliente") {
        int op = menu.mostrarMenu("Cliente");
        system("cls");
        switch (op) {
        case 1: sistemaOrdenes(); break;
        case 3: sistemaPagos(); break;
        case 4: break;
        }
        return op;
    }
	else if (tipoCuenta == "Trabajador") {
		int op = menu.mostrarMenu("Trabajador");
		system("cls");
		switch (op) {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
		case 6: iniciarSesion(); break;
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
        case 4: 
            Boleta * boleta = ordenes.confirmar(usuarioCliente.getPersonal());
            boletas.push_back(boleta);
            break;
        }
    } while (op_ordenes != 5 && op_ordenes != 4);


}

