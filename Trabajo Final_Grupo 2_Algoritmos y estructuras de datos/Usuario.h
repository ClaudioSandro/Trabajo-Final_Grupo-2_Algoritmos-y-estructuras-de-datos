#pragma once
#include "Recursos.h"

class Usuario {

protected:

	info personal;

public:

	Usuario() {
		personal.nombre = "Rocky Martinez";
		personal.direccion = "Av. Rojo 2430 Dpto. 201";
		personal.telefono = "942358573";
	}

	info getPersonal() { return personal; }
	void setPersonal(info _personal) { personal = _personal; }

	void mostrar() {
		cout << "Nombre: " << personal.nombre << endl;
		cout << "Direccion: " << personal.direccion << endl;
		cout << "Telefono: " << personal.telefono << endl;
	}
};