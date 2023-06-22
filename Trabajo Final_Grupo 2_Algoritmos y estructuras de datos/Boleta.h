#pragma once
#include "Orden.h"

class Boleta {

private:

	Orden orden;
	info us;
	string estado = "Por pagar";

public:
	Boleta(info _us, Orden _orden) {
		us = _us; orden = _orden;
	}

	void setEstado(string _estado) { estado = _estado; }
	string getEstado() { return estado; }

	void mostrar() {
		linea();
		cout << "              SAPORE D'ITALIA" << endl;
		linea();
		cout << "DATOS DEL CLIENTE:" << endl << endl;
		cout << "Nombre: " << us.nombre << endl;
		cout << "Direccion: " << us.direccion << endl;
		cout << "Telefono: " << us.telefono << endl;
		linea();
		cout << "DETALLES DEL PEDIDO:" << endl << endl;
		orden.mostrarOrden();
		linea();
		cout << "Estado: " << estado << endl;
		linea();

	}
};