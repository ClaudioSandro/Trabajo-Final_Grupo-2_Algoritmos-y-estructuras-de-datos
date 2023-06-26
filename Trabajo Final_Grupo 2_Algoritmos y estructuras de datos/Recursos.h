#pragma once
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include "Lista.h"
#include <algorithm>
#include <cctype>

using namespace System;
using namespace std;

struct tarjeta {
	string empresa;
	string titular;
	string numero;
	string codigo;
	string vencimiento;
};

struct DCliente {
	string nombreCliente;
	string telefonoCliente;
	string direccionCliente;
	string contraseniaCliente;
	string usuarioCliente;
};

struct info {
	string nombre;
	string telefono;
	string direccion;
};

struct data {
	string usuario;
	string contraseña;
};

void linea() {
	cout << "--------------------------------------------"; cout << endl;
}