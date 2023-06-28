#include <iostream>
#include "Sesion.h"


int main()
{
    Sesion sistema;
    HashTable<USCON, DCliente> hashtable = sistema.iniciar();
    
    do {
        sistema.iniciarSesion(hashtable);
    } while (true);

    return 0;
}