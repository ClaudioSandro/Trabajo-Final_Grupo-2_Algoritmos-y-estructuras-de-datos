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
    Lista<Boleta*> boletas;

public:

    //get-set
    string getTipoCuenta() { return tipoCuenta; }
    void setTipoCuenta(string _tipoCuenta) { tipoCuenta = _tipoCuenta; }

    int opcionBoletas();
    int opcionPagarBoleta();
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

int Sesion::opcionPagarBoleta() {
    int op;
    cout << "SELECCIONE LA BOLETA QUE DESEA PAGAR" << endl << endl;
    int cont = 0;
    for (int i = 0; i < boletas.size(); i++) {
        if (boletas[i]->getEstado() == "Por pagar") {
            linea();
            cout << "BOLETA 00" << cont + 1 << endl;
            
            boletas[i]->mostrar(); cout << endl << endl;
        }
        cont++;
    }
    cout << "NINGUNA 000" << endl << endl << endl;
    cout << "Ingrese el numero de la boleta a pagar: "; cin >> op;
    return op;
}

void Sesion::iniciarSesion() {
    Login loginSesion;

    int opcionSesion;
    do {
        system("cls");
        cout << "BIENVENIDO A LA APP SAPORE D'ITALIA" << endl << endl;
        cout << "1. Login as Cliente" << endl;
        cout << "2. Login as Trabajador" << endl;
        cout << "3. Salir de Sapore D' Italia" << endl << endl;
        cout << "Opcion: ";
        cin >> opcionSesion;
        info datos;
        switch (opcionSesion) {
        case 1:
            if (loginSesion.ValidaCliente(datos) == true) {
                system("cls");
                setTipoCuenta("Cliente");
                usuarioCliente.setPersonal(datos);
                int op;
                do {
                    op = menuPrincipal();
                } while (op!= 5);
                
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
        int op = menu.mostrarMenu("Cliente", usuarioCliente.getPersonal());
        system("cls");
        switch (op) {
        case 1: sistemaOrdenes(); break;
        case 2: sistemaBoletas(); break;
        case 3: sistemaPagos(); break;
        case 4: 
            cout << "DATOS DE CUENTA" << endl << endl;
            usuarioCliente.mostrar(); cout << endl;
            cout << "Presione Enter para continuar...";
            cin.ignore(); cin.get(); system("cls");

            break;
        case 5: break;
        }
        return op;
    }
	else if (tipoCuenta == "Trabajador") {
		int op = menu.mostrarMenu("Trabajador", usuarioCliente.getPersonal());
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
        int nboleta;
        int op = pagos.menuPagos();
        switch (op)
        {
        case 1:
            nboleta = opcionPagarBoleta() - 1;            
            if (nboleta != -1 && boletas[nboleta]->getEstado() == "Por pagar") {
                system("cls");
                pagos.pagar(usuarioCliente, boletas[nboleta]);
            }
            else {
                system("cls");
            }
            break;
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
            Boleta * bol = ordenes.confirmar(usuarioCliente.getPersonal());
            
            int op;
            cout << "Desea pagar su boleta en este momento?" << endl << endl;
            cout << "1. Si" << endl;
            cout << "2. Pagar mas tarde " << endl << endl;
            cout << "Opcion: "; cin >> op; cout << endl;
            if (op == 1) {
                system("cls");
                pagos.pagar(usuarioCliente, bol); boletas.push_back(bol); break;
            }
            else if (op == 2) {
                boletas.push_back(bol);
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
            for (int i = 0; i < boletas.size(); i++) {
                if (boletas[i]->getEstado() == "Cancelado" || boletas[i]->getEstado() == "Pago durante entrega") {
                    linea();
                    cout << "BOLETA 00" << cont + 1 << endl;
                    
                    boletas[i]->mostrar(); cout << endl << endl;
                }
                cont++;
            }
            cout << "Presione Enter para continuar...";
            cin.ignore(); cin.get(); system("cls");
        }

        if (op == 2) {
            int cont = 0;
            for (int i = 0; i < boletas.size(); i++) {
                if (boletas[i]->getEstado() == "Por pagar") {
                    linea();
                    cout << "BOLETA 00" << cont + 1 << endl;
                    
                    boletas[i]->mostrar(); cout << endl << endl;
                }
                cont++;
            }
            cout << "Presione Enter para continuar...";
            cin.ignore(); cin.get(); system("cls");
        }

        if (op == 3) {
            int cont = 0;
            for (int i = 0; i < boletas.size(); i++) {
                linea();
                cout << "BOLETA 00" << cont + 1 << endl;
                
                boletas[i]->mostrar(); cout << endl << endl;
                cont++;
            }
            cout << "Presione Enter para continuar...";
            cin.ignore(); cin.get(); system("cls");
        }
    } while (op != 0);
}

