#pragma once
template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
};

template <typename T>
class Lista {
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
    int tamano;

public:
    Lista() : primero(nullptr), ultimo(nullptr), tamano(0) {}


    void push_back(const T& elemento) {
        Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
        if (tamano == 0) {
            primero = nuevoNodo;
            ultimo = nuevoNodo;
        }
        else {
            ultimo->siguiente = nuevoNodo;
            ultimo = nuevoNodo;
        }
        tamano++;
    }

    void erase(int posicion) {
        if (posicion < 0 || posicion >= tamano)
            return;

        if (posicion == 0) {
            Nodo<T>* nodoEliminar = primero;
            primero = primero->siguiente;
            delete nodoEliminar;
            tamano--;
            if (tamano == 0)
                ultimo = nullptr;
        }
        else {
            Nodo<T>* nodoAnterior = nullptr;
            Nodo<T>* nodoActual = primero;
            int contador = 0;
            while (contador < posicion) {
                nodoAnterior = nodoActual;
                nodoActual = nodoActual->siguiente;
                contador++;
            }
            nodoAnterior->siguiente = nodoActual->siguiente;
            delete nodoActual;
            tamano--;
            if (posicion == tamano)
                ultimo = nodoAnterior;
        }
    }

    int size() {
        return tamano;
    }

    Nodo<T>* begin() const {
        return primero;
    }

    Nodo<T>* end() const {
        return nullptr;
    }

    class Iterator {
    private:
        Nodo<T>* nodo;

    public:
        Iterator(Nodo<T>* n) : nodo(n) {}

        Iterator& operator++() {
            nodo = nodo->siguiente;
            return *this;
        }

        bool operator!=(const Iterator& otro) const {
            return nodo != otro.nodo;
        }

        T& operator*() const {
            return nodo->dato;
        }
    };

    int size() const {
        return tamano;
    }

    T& operator[](int posicion) const {
        Nodo<T>* nodo = primero;
        int contador = 0;
        while (contador < posicion && nodo != nullptr) {
            nodo = nodo->siguiente;
            contador++;
        }
        return nodo->dato;
    }
};
