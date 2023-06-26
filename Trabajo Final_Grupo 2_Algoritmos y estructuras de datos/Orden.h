#pragma once
#include "Bebidas.h"
#include "Pizzas.h"
#include "Pastas.h"
#include "Postres.h"

class Orden {

public:

    Lista<Pizza*> pizzas;
    Lista<Pasta*> pastas;
    Lista<Bebida*> bebidas;
    Lista<Postre*> postres;
    double total = 0.0;


    Orden() {};
    ~Orden();

    void mostrarOrden();
    void mostrarTipo(string tipo);


};

Orden::~Orden() {
    /*for (const auto& pizza : pizzas) {
        delete pizza;
    }
    for (const auto& pasta : pastas) {
        delete pasta;
    }
    for (const auto& bebida : bebidas) {
        delete bebida;
    }
    for (const auto& postre : postres) {
        delete postre;
    }*/
}

void Orden::mostrarOrden() {

    
    for (int i = 0; i < pizzas.size(); i++) {
        cout << pizzas[i]->getNombre() << " S/" << pizzas[i]->getPrecio();
        cout << endl;
    }

    for (int i = 0; i < pastas.size(); i++) {
        cout << pastas[i]->getNombre() << " S/" << pastas[i]->getPrecio();
        cout << endl;  
    }

    for (int i = 0; i < bebidas.size(); i++) {
        cout << bebidas[i]->getNombre() << " S/" << bebidas[i]->getPrecio();
        cout << endl;
    }

    for (int i = 0; i < postres.size(); i++) {
        cout << postres[i]->getNombre() << " S/" << postres[i]->getPrecio();
        cout << endl;       
    }
    cout << endl;
    cout << "Total: S/" << total << endl;
}

void Orden::mostrarTipo(string tipo) {

    if (tipo == "pizza") {
        int cont = 1;
        for (int i = 0; i < pizzas.size(); i++) {
            cout << cont << ". " << pizzas[i]->getNombre();
            cout << endl;
            cont++;
        }
    }

    if (tipo == "pasta") {
        int cont = 1;
        for (int i = 0; i < pastas.size(); i++) {
            cout << cont << ". " << pastas[i]->getNombre();
            cout << endl;
            cont++;
        }
    }

    if (tipo == "bebida") {
        int cont = 1;
        for (int i = 0; i < bebidas.size(); i++) {
            cout << cont << ". " << bebidas[i]->getNombre();
            cout << endl;
            cont++;
        }
    }

    if (tipo == "postre") {
        int cont = 1;
        for (int i = 0; i < postres.size(); i++) {
            cout << cont << ". " << postres[i]->getNombre();
            cout << endl;
            cont++;
        }
    }
}

