#pragma once
#include "OrdenBuilder.h"
#include "Pizzas.h"

class SistemaOrdenes {

private:
	OrdenBuilder* builder;

public:

	SistemaOrdenes() { builder = new OrdenBuilder();}
	~SistemaOrdenes() { delete builder;}

	int menuSistemaOrdenes();

	int opcionAgregar();
	int opcionEliminar();
	int opcionPizzas();
	int opcionEliminarTipo(string tipo);

	void agregarPizza();
	void eliminarTipo(string tipo);
	
	void agregar();
	void eliminar();
	void confirmar();
	void mostrarOrden();
	
};

int SistemaOrdenes::menuSistemaOrdenes() {
	int op;

	cout << "NUEVA ORDEN" << endl << endl;
	cout << "1. Agregar al pedido" << endl;
	cout << "2. Eliminar del pedido" << endl;
	cout << "3. Mostrar Orden" << endl;
	cout << "4. Confirmar Orden" << endl;
	cout << "5. Cancelar Orden" << endl << endl;
	cout << "Opcion: "; cin >> op;
	system("cls");

	return op;
}

int SistemaOrdenes::opcionAgregar() {
	int op;

	cout << "SELECCIONE LO QUE DESEE AGREGAR" << endl << endl;
	cout << "1. Agregar pizza" << endl;
	cout << "2. Agregar pasta" << endl;
	cout << "3. Agregar bebida" << endl;
	cout << "4. Agregar Postre" << endl;
	cout << "5. Volver" << endl << endl;
	cout << "Opcion: "; cin >> op;
	system("cls");

	return op;
}

int SistemaOrdenes::opcionEliminar() {
	int op;

	cout << "SELECCIONE LO QUE DESEE ELIMINAR" << endl << endl;
	cout << "1. Eliminar pizza" << endl;
	cout << "2. Eliminar pasta" << endl;
	cout << "3. Eliminar bebida" << endl;
	cout << "4. Eliminar Postre" << endl;
	cout << "5. Volver" << endl << endl;
	cout << "Opcion: "; cin >> op;
	system("cls");

	return op;
}

int SistemaOrdenes::opcionPizzas() {
	int op;

	cout << "SELECCIONE LA PIZZA QUE DESEA AGREGAR" << endl << endl;
	cout << "1. Americana" << endl;
	cout << "2. Hawaiana" << endl;
	cout << "3. " << endl;
	cout << "4. " << endl;
	cout << "5. Volver" << endl << endl; 
	cout << "Opcion: "; cin >> op; cout << endl;
	
	return op;
}

int SistemaOrdenes::opcionEliminarTipo(string tipo) {
	int op;
	cout << "SELECCIONE LA PIZZA A ELIMINAR " << endl << endl;
	builder->mostrarEnum(tipo);
	cout << "0. Volver"; cout << endl << endl;
	cout << "Opcion: "; cin >> op; cout << endl;
	return op;
}

void SistemaOrdenes::agregar() {

	int op_agregar;
	do {
		op_agregar = opcionAgregar();

		switch (op_agregar)
		{
		case 1: agregarPizza(); break;
		}
	} while (op_agregar != 5);

	system("cls");
}

void SistemaOrdenes::agregarPizza() {

	int opPizzas = opcionPizzas();

	if (opPizzas == 1) {
		Pizza* pizza = new Americana();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Americana al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPizzas == 2) {
		Pizza* pizza = new Hawaiana();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Hawaiana al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}			
}

void SistemaOrdenes::eliminar() {
	int op_eliminar;
	do {
		op_eliminar = opcionEliminar();

		switch (op_eliminar)
		{
		case 1: eliminarTipo("pizza"); break;
		}
	} while (op_eliminar != 5);

	system("cls");
}

void SistemaOrdenes::eliminarTipo(string tipo) {

	if (tipo == "pizza") {
		int op;
		do {
			op = opcionEliminarTipo(tipo);
			if (op != 0) {
				builder->eliminarPizza(op - 1);
				cout << "Se elimino la pizza en la posicion " << op << "...Presione Enter para continuar...";
				cin.ignore(); cin.get();
				system("cls");
			}
		} while (op != 0);
	}
	system("cls");	
}

void SistemaOrdenes::confirmar(){}

void SistemaOrdenes::mostrarOrden() {

	cout << "DETALLES DEL PEDIDO ACTUAL" << endl << endl;
	builder->mostrar();
	cout << "Presione Enter para continuar...";
	cin.ignore(); cin.get(); system("cls");
}