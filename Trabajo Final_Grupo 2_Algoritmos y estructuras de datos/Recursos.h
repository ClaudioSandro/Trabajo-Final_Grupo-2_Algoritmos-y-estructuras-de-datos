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
#include "HashTable.h"

using namespace System;
using namespace std;

struct tarjeta {
    std::string empresa;
    std::string titular;
    std::string numero;
    std::string codigo;
    std::string vencimiento;

    bool operator==(const tarjeta& other) const {
        return (empresa == other.empresa && titular == other.titular && numero == other.numero && codigo == other.codigo && vencimiento == other.vencimiento);
    }
};

struct DCliente {
    std::string nombreCliente;
    std::string telefonoCliente;
    std::string direccionCliente;
    std::string contraseniaCliente;
    std::string usuarioCliente;

    bool operator==(const DCliente& other) const {
        return (nombreCliente == other.nombreCliente && telefonoCliente == other.telefonoCliente && direccionCliente == other.direccionCliente && contraseniaCliente == other.contraseniaCliente && usuarioCliente == other.usuarioCliente);
    }
};

struct info {
    std::string nombre;
    std::string telefono;
    std::string direccion;

    bool operator==(const info& other) const {
        return (nombre == other.nombre && telefono == other.telefono && direccion == other.direccion);
    }
};



void linea() {
	cout << "--------------------------------------------"; cout << endl;
}