#pragma once
#include "Recursos.h"


class ValidarCliente
{
public:
    void leer() {
        ifstream archivo("Cliente.txt");
        if (!archivo.is_open()) {
            cout << "Error al abrir el archivo" << endl;
        }
        string line;

        while (getline(archivo, line)) {
            stringstream s(line);
            string nameCliente, phonenumberCliente, directionCliente, userCliente, passwordCliente;
            string aux;

            getline(s, aux, ',');
            nameCliente = aux;
            getline(s, aux, ',');
            phonenumberCliente = aux;
            getline(s, aux, ',');
            directionCliente = aux;
            getline(s, aux, ',');
            userCliente = aux;
            getline(s, aux, ',');
            passwordCliente = aux;

        }

    }
};
