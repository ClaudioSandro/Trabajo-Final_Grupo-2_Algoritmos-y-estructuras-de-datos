#pragma once
#include "MenuOpciones.h"
#include "SistemaPagos.h"
#include "SistemaOrdenes.h"
#include "Login.h"



class Sesion {

private:
    
    Cliente usuarioCliente;
    //Trabajador usuarioTrabajador
    Login loginSesion;
    string tipoCuenta = "";
    vector<Boleta*> boletas;

public:

    //get-set
    string getTipoCuenta() { return tipoCuenta; }
    void setTipoCuenta(string _tipoCuenta) { tipoCuenta = _tipoCuenta; }

    int opcionBoletas();
    //principales
    void iniciarSesion();
    int menuPrincipal();
    void sistemaOrdenes();
    void sistemaPagos();
    void sistemaBoletas();
};

int Sesion::opcionBoletas() {
    int op;

    cout << "Que boletas desea ver?" << endl << endl;
    cout << "1. Boletas pagadas" << endl;
    cout << "2. Boletas por pagar" << endl;
    cout << "3. Todas las boletas" << endl;
    cout << "0. Volver" << endl << endl;
    cout << "Opcion: "; cin >> op;
    system("cls");
    return op;
}

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

    MenuOpciones menu;
    string tipoCuenta = getTipoCuenta(); //Esto se obtiene del sistema de validacion de cuenta

    if (tipoCuenta == "Cliente") {
        int op = menu.mostrarMenu("Cliente");
        system("cls");
        switch (op) {
        case 1: sistemaOrdenes(); break;
        case 2: sistemaBoletas(); break;
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
    SistemaPagos pagos;

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
            
            int op;
            cout << "Desea pagar su boleta en este momento?" << endl << endl;
            cout << "1. Si" << endl;
            cout << "2. Pagar mas tarde " << endl << endl;
            cout << "Opcion: "; cin >> op; cout << endl;
            if (op == 1) {
                system("cls");
                pagos.pagar(usuarioCliente); boletas.push_back(boleta); break;
            }
            else if (op == 2) {
                boletas.push_back(boleta);
                cout << "El pago de la boleta queda pendiente..." << endl;
                cout << "Recuerde hacer el pago de su boleta mediante el sistema de pagos" << endl << endl;
                cout << "Presione Enter para continuar...";
                cin.ignore(); cin.get(); system("cls");
                break;
            }
            
        }
    } while (op_ordenes != 0 && op_ordenes != 4);


}

void Sesion::sistemaBoletas() {
    int op;

    do {
        op = opcionBoletas();

        if (op == 1) {
            int cont = 0;
            for (const auto& boleta : boletas) {
                if (boleta->getEstado() == "Cancelado" || boleta->getEstado() == "En efectivo") {
                    cout << "BOLETA 00" << cont + 1 << endl << endl;
                    boleta->mostrar(); cout << endl;
                }
                cont++;
            }
            cout << "Presione Enter para continuar...";
            cin.ignore(); cin.get(); system("cls");
        }

        if (op == 2) {
            int cont = 0;
            for (const auto& boleta : boletas) {
                if (boleta->getEstado() == "Por pagar") {
                    cout << "BOLETA 00" << cont + 1 << endl << endl;
                    boleta->mostrar(); cout << endl;
                }
                cont++;
            }
            cout << "Presione Enter para continuar...";
            cin.ignore(); cin.get(); system("cls");
        }

        if (op == 3) {
            int cont = 0;
            for (const auto& boleta : boletas) {
                cout << "BOLETA 00" << cont + 1 << endl << endl;
                boleta->mostrar(); cout << endl;
                cont++;
            }
            cout << "Presione Enter para continuar...";
            cin.ignore(); cin.get(); system("cls");
        }
    } while (op != 0);
}

