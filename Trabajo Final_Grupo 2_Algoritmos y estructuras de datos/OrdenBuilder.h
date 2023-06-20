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

    void mostrar() {
        orden.mostrarOrden();
    }

    Orden obtenerOrden() {
        return orden;
    }
};