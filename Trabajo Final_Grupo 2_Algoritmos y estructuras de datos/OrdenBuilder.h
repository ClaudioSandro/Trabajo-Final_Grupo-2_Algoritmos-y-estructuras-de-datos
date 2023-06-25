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

    void eliminarPasta(int pos) {
        Pasta* pasta = orden.pastas[pos];
        orden.total -= pasta->getPrecio();
        orden.pastas.erase(orden.pastas.begin() + pos);
    }

    void eliminarBebida(int pos) {
        Bebida* bebida = orden.bebidas[pos];
        orden.total -= bebida->getPrecio();
        orden.bebidas.erase(orden.bebidas.begin() + pos);
    }

    void eliminarPostre(int pos) {
        Postre* postre = orden.postres[pos];
        orden.total -= postre->getPrecio();
        orden.postres.erase(orden.postres.begin() + pos);
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

   
};