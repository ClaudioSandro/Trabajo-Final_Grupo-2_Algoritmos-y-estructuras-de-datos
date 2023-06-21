#pragma once
#include "Orden.h"

class OrdenBuilder {
private:
	Orden orden;

public:

    void agregarPizza(Pizza* pizza) {
        orden.pizzas.push_back(pizza);
        orden.total += pizza->getPrecio();
    }

    void agregarPasta(Pasta* pasta) {
        orden.pastas.push_back(pasta);
        orden.total += pasta->getPrecio();
    }

    void agregarBebida(Bebida* bebida) {
        orden.bebidas.push_back(bebida);
        orden.total += bebida->getPrecio();
    }

    void agregarPostre(Postre* postre) {
        orden.postres.push_back(postre);
        orden.total += postre->getPrecio();
    }

    void eliminarPizza(int pos) {
        Pizza* pizza = orden.pizzas[pos];
        orden.total -= pizza->getPrecio();
        orden.pizzas.erase(orden.pizzas.begin() + pos);    
    }

    void mostrar() {
        orden.mostrarOrden();
    }

    void mostrarEnum(string tipo) {
        orden.mostrarTipo(tipo);
    }

    Orden obtenerOrden() {
        return orden;
    }

    string estado() { return orden.getEstado(); }
};