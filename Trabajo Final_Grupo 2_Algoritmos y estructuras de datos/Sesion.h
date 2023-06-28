#pragma once
#include "MenuOpciones.h"
#include "SistemaPagos.h"
#include "SistemaOrdenes.h"
#include "Login.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

string generateOrderNumber(int orderCount) {
    string orderNumber = "#";
    orderNumber += std::to_string(orderCount);
    orderNumber.insert(orderNumber.begin() + 1, 5 - orderNumber.length(), '0');
    return orderNumber;
}

string getRandomFood() {
    string foods[] = { "Pizza Americana", "Pizza Hawaina", "Pizza Mozzarela",
                           "Pasta Raviolis", "Pasta Spaghetti a lo Alfredo", "Pasta Pasta Puttanesca" };
    int index = rand() % 6;
    return foods[index];
}

string getRandomBeverage() {
    string beverages[] = { "AguaMinera", "IncaKola", "CocaCola" };
    int index = rand() % 3;
    return beverages[index];
}

string getRandomDessert() {
    string desserts[] = { "Pizza_dechocolate", "Churro_D_ITALIA", "Rolls_De_Manajar" };
    int index = rand() % 3;
    return desserts[index];
}

double getPrice(string item) {
    if (item == "Pizza Americana")
        return 26.90;
    else if (item == "Pizza Hawaina")
        return 32.90;
    else if (item == "Pizza Mozzarela")
        return 29.90;
    else if (item == "Pasta Raviolis")
        return 24.90;
    else if (item == "Pasta Spaghetti a lo Alfredo")
        return 20.00;
    else if (item == "Pasta Pasta Puttanesca")
        return 19.00;
    else if (item == "AguaMinera")
        return 3.00;
    else if (item == "IncaKola" || item == "CocaCola")
        return 9.50;
    else if (item == "Pizza_dechocolate")
        return 19.90;
    else if (item == "Churro_D_ITALIA")
        return 5.90;
    else if (item == "Rolls_De_Manajar")
        return 10.90;
    else
        return 0.00;
}

struct Order {
    string orderNumber;
    string food;
    string beverage;
    string dessert;
    double totalPrice;
};

// Nodo de árbol binario
struct TreeNode {
    Order order;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const Order& o) : order(o), left(nullptr), right(nullptr) {}
};

// Insertar un nuevo nodo en el árbol binario
TreeNode* insert(TreeNode* root, const Order& order) {
    if (root == nullptr)
        return new TreeNode(order);
    if (order.orderNumber < root->order.orderNumber)
        root->left = insert(root->left, order);
    else if (order.orderNumber > root->order.orderNumber)
        root->right = insert(root->right, order);
    return root;
}

// Eliminar un nodo del árbol binario
TreeNode* remove(TreeNode* root, const string& orderNumber) {
    if (root == nullptr)
        return root;
    if (orderNumber < root->order.orderNumber)
        root->left = remove(root->left, orderNumber);
    else if (orderNumber > root->order.orderNumber)
        root->right = remove(root->right, orderNumber);
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* minRight = root->right;
        while (minRight->left != nullptr)
            minRight = minRight->left;
        root->order = minRight->order;
        root->right = remove(root->right, minRight->order.orderNumber);
    }
    return root;
}

// Realizar un recorrido inorden del árbol binario y almacenar las órdenes en un vector
void inorderTraversal(TreeNode* root, vector<Order>& orders) {
    if (root != nullptr) {
        inorderTraversal(root->left, orders);
        orders.push_back(root->order);
        inorderTraversal(root->right, orders);
    }
}

// Filtrar y mostrar las órdenes según el tipo de filtro seleccionado
void filterOrders(TreeNode* root, int filterType) {
    if (root == nullptr) {
        cout << "No hay ordenes registradas." << endl;
        return;
    }

    vector<Order> orders;
    inorderTraversal(root, orders);

    switch (filterType) {
    case 1: {
        // Filtrar por comidas en orden alfabético
        sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
            return a.food < b.food;
            });
        break;
    }
    case 2: {
        // Filtrar por precios de forma ascendente
        sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
            return a.totalPrice < b.totalPrice;
            });
        break;
    }
    default:
        cout << "Opcion de filtro invalida." << endl;
        return;
    }

    // Mostrar las órdenes filtradas
    for (const auto& order : orders) {
        cout << "Orden numero " << order.orderNumber << " - "
            << order.food << ", " << order.beverage << ", " << order.dessert
            << " - Precio: " << order.totalPrice << endl;
    }
}


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
                } while (op != 5);

            }
            else {
                cout << "No se pudo iniciar sesion" << endl;
            }
            break;
        case 2:
            if (loginSesion.ValidaTrabajador() == true) {
                system("cls");
                TreeNode* root = nullptr;

                srand(static_cast<unsigned int>(time(nullptr)));

                for (int i = 1; i <= 1000; ++i) {
                    string orderNumber = generateOrderNumber(i);
                    string food = getRandomFood();
                    string beverage = getRandomBeverage();
                    string dessert = getRandomDessert();

                    double foodPrice = getPrice(food);
                    double beveragePrice = getPrice(beverage);
                    double dessertPrice = getPrice(dessert);
                    double totalPrice = foodPrice + beveragePrice + dessertPrice;

                    Order newOrder;
                    newOrder.orderNumber = orderNumber;
                    newOrder.food = food;
                    newOrder.beverage = beverage;
                    newOrder.dessert = dessert;
                    newOrder.totalPrice = totalPrice;

                    root = insert(root, newOrder);

                    cout << "orden: " << orderNumber << "-" << food << ", " << beverage << ", " << dessert
                        << "-precio: " << totalPrice << endl;

                }
                system("cls");
                int option;
                bool loggedIn = true;

                while (loggedIn) {
                    cout << "------- Menu principal -------" << endl;
                    cout << "1. Filtrar ordenes" << endl;
                    cout << "2. Atender orden" << endl;
                    cout << "3. Log out" << endl;
                    cout << "Ingrese su opción: ";
                    cin >> option;
                    system("cls");
                    switch (option) {
                    case 1: {
                        int filterOption;
                        cout << "------- Filtrar ordenes -------" << endl;
                        cout << "1. Filtrar por comidas" << endl;
                        cout << "2. Filtrar por precios" << endl;
                        cout << "3. Filtrar por # de orden" << endl;
                        cout << "Ingrese su opción: ";
                        cin >> filterOption;

                        // Limpiar la pantalla (código omitido)
                        system("cls");
                        filterOrders(root, filterOption);
                        break;
                    }
                    case 2: {
                        string orderNumber;
                        cout << "------- Atender orden -------" << endl;
                        cout << "Inserte el numero de orden: ";
                        cin >> orderNumber;

                        // Eliminar la orden del árbol
                        root = remove(root, orderNumber);

                        cout << "Orden numero " << orderNumber << " atendida." << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                    case 3:
                        loggedIn = false;
                        break;
                    default:
                        cout << "Opcion invalida. Intente nuevamente." << endl;
                        break;
                    }
                }
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
        case 3: iniciarSesion(); break;
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

