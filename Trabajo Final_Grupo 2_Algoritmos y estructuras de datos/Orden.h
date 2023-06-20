#pragma once
#include "Bebidas.h"
#include "Pizzas.h"
#include "Pastas.h"
#include "Postres.h"

class Orden {

public:

    vector<Pizza*> pizzas;
    vector<Pasta*> pastas;
    vector<Bebida*> bebidas;
    vector<Postre*> postres;
    double total = 0.0;

    ~Orden();
    void mostrarOrden();

};

Orden::~Orden() {
    for (const auto& pizza : pizzas) {
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
    }
}

void Orden::mostrarOrden() {
    
    
    for (const auto& pizza : pizzas) {
        cout << pizza->getNombre() << " S/" << pizza->getPrecio();
        cout << endl;
    }
     
    for (const auto& pasta : pastas) {
        cout << pasta->getNombre() << " S/" << pasta->getPrecio();
        cout << endl;
    }
    
    for (const auto& bebida : bebidas) {
        cout << bebida->getNombre() << " S/" << bebida->getPrecio();
        cout << endl;
    }
    
    for (const auto& postre : postres) {
        cout << postre->getNombre() << " S/" << postre->getPrecio();
        cout << endl;
    }
    cout << endl;
    cout << "Total: S/" << total << endl << endl;
}