#pragma once
#include "Recursos.h"

class Producto {

protected:
	string nombre;
	double precio;

public:
	Producto(string _nombre, double _precio) {
		nombre = _nombre; precio = _precio;
	}

	string getNombre() { return nombre; }
	double getPrecio() { return precio; }
};

class Pizza : public Producto {

public:
	Pizza(string _nombre, double _precio): Producto(_nombre,_precio) {}

};

class Pasta : public Producto {

public:
	Pasta(string _nombre, double _precio) : Producto(_nombre, _precio) {}

};

class Bebida : public Producto {

public:
	Bebida(string _nombre, double _precio) : Producto(_nombre, _precio) {}

};

class Postre : public Producto {

public:
	Postre(string _nombre, double _precio) : Producto(_nombre, _precio) {}

};