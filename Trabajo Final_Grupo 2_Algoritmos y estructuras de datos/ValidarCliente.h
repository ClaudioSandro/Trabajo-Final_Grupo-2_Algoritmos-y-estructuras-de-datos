#pragma once
#include "Recursos.h"


class ValidarCliente
{
public:
	bool validacionClientaso(string userCliente, string passwordCliente, info &datos, HashTable<USCON, DCliente>& hash) {
		
		USCON y;
		y.usuario = userCliente; y.contrasena = passwordCliente;
		DCliente result;

		if (hash.getData(y, result)) {
			datos.nombre = result.nombreCliente; datos.direccion = result.direccionCliente; datos.telefono = result.telefonoCliente;
			return true;
		}
		else {
			cout << "Usuario y/o contrasenia incorrectos" << endl;
			return false;
		}

		
	}
};
