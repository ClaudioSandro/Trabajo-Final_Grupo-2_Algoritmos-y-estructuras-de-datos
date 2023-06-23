#pragma once
#include "OrdenBuilder.h"
#include "Boleta.h"

class SistemaOrdenes {

private:
	OrdenBuilder* builder;

public:

	SistemaOrdenes() { builder = new OrdenBuilder(); }
	~SistemaOrdenes() { delete builder; }

	int menuSistemaOrdenes();

	int opcionAgregar();
	int opcionEliminar();
	int opcionPizzas();
	int opcionBebidas();
	int opcionPastas();
	int opcionPostres(){ return 0; }
	int opcionEliminarTipo(string tipo);

	void agregarPizza();
	void agregarPasta();
	void agregarBebida(){ }
	void agregarPostre(){ }
	void eliminarTipo(string tipo);

	bool preguntaPagar();

	void agregar();
	void eliminar();
	Boleta* confirmar(info us);
	void mostrarOrden();

};

int SistemaOrdenes::menuSistemaOrdenes() {
	int op;

	cout << "NUEVA ORDEN" << endl << endl;
	cout << "1. Agregar al pedido" << endl;
	cout << "2. Eliminar del pedido" << endl;
	cout << "3. Mostrar Orden" << endl;
	cout << "4. Confirmar Orden" << endl;
	cout << "0. Cancelar Orden" << endl << endl;
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
	cout << "0. Volver" << endl << endl;
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
	cout << "0. Volver" << endl << endl;
	cout << "Opcion: "; cin >> op;
	system("cls");

	return op;
}

int SistemaOrdenes::opcionPizzas() {
	int op;
	Pizza* x;
	cout << "SELECCIONE LA PIZZA QUE DESEA AGREGAR" << endl << endl;
	x = new Americana();
	cout << "1. Americana S/" << x->getPrecio() << endl;
	x = new Hawaiana();
	cout << "2. Hawaiana S/" << x->getPrecio() << endl;
	x = new Mozzarela();
	cout << "3. Mozzarela S/" << x->getPrecio() << endl;
	x = new Pepperoni();
	cout << "4. Pepperoni S/" << x->getPrecio() << endl;
	x = new Vegetariana();
	cout << "5. Vegetariana S/" << x->getPrecio() << endl;
	x = new Suprema();
	cout << "6. Suprema S/" << x->getPrecio() << endl;
	x = new Barbacoa();
	cout << "7. Barbacoa S/" << x->getPrecio() << endl;
	x = new Calzone();
	cout << "8. Calzone S/" << x->getPrecio() << endl;
	cout << "0. Volver" << endl << endl;
	cout << "Opcion: "; cin >> op; cout << endl;

	delete x;
	return op;
}

int SistemaOrdenes::opcionBebidas() {
	int op;
	

	cout << "SELECCIONE LA PIZZA QUE DESEA AGREGAR" << endl << endl;
	
	cout << "1. Americana " << endl;
	cout << "2. Hawaiana " << endl;
	cout << "3. Mozzarela " << endl;
	cout << "4. Pepperoni " << endl;
	cout << "5. Vegetariana " << endl;
	cout << "6. Suprema " << endl;
	cout << "7. Barbacoa " << endl;
	cout << "8. Calzone " << endl;
	cout << "0. Volver" << endl << endl;
	cout << "Opcion: "; cin >> op; cout << endl;

	return op;
}

int SistemaOrdenes::opcionPastas() {
	int op;
	Pasta* x;

	cout << "SELECCIONE LA PASTA QUE DESEA AGREGAR" << endl << endl;
	x = new Spaghetti_a_lo_Alfredo();
	cout << "1. Spaghetti a lo Alfredo S/" << x->getPrecio() << endl;
	x = new Pasta_Puttanesca();
	cout << "2. Pasta Puttanesca S/" << x->getPrecio() << endl;
	x = new Tallarines_y_Champinones();
	cout << "3. Tallarines en Salsa Blanca y Mushrooms S/" << x->getPrecio() << endl;
	x = new Raviolis();
	cout << "4. Raviolis S/" << x->getPrecio() << endl;
	x = new Lasagna_Original();
	cout << "5. Lasagna Original Italiana S/" << x->getPrecio() << endl;
	x = new Lasagna_Especial();
	cout << "6. Lasagna Especial de la Casa S/" << x->getPrecio() << endl;
	cout << "0. Volver" << endl << endl;
	cout << "Opcion: "; cin >> op; cout << endl;

	delete x;
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
		case 2: agregarPasta(); break;
		case 3: agregarBebida(); break;
		case 4: agregarPostre(); break;
		}
	} while (op_agregar != 0);

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
	if (opPizzas == 3) {
		Pizza* pizza = new Mozzarela();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Mozzarela al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPizzas == 4) {
		Pizza* pizza = new Pepperoni();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Pepperoni al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPizzas == 5) {
		Pizza* pizza = new Vegetariana();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Vegetariana al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPizzas == 6) {
		Pizza* pizza = new Suprema();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Suprema al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPizzas == 7) {
		Pizza* pizza = new Barbacoa();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Barbacoa al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPizzas == 8) {
		Pizza* pizza = new Calzone();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Calzone al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
}

void SistemaOrdenes::agregarPasta() {

	int opPastas = opcionPastas();

	if (opPastas == 1) {
		Pasta* pasta = new Spaghetti_a_lo_Alfredo();
		builder->agregarPasta(pasta);
		cout << "Se agrego Spaghetti a lo Alfredo al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPastas == 2) {
		Pasta* pasta = new Pasta_Puttanesca();
		builder->agregarPasta(pasta);
		cout << "Se agrego Pasta Puttanesca al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPastas == 3) {
		Pasta* pasta = new Tallarines_y_Champinones();
		builder->agregarPasta(pasta);
		cout << "Se agrego Tallarines en Salsa Blanca y Mushrooms al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPastas == 4) {
		Pasta* pasta = new Raviolis();
		builder->agregarPasta(pasta);
		cout << "Se agrego Raviolis al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPastas == 5) {
		Pasta* pasta = new Lasagna_Original();
		builder->agregarPasta(pasta);
		cout << "Se agrego Lasagna Original Italiana al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); system("cls");
	}
	if (opPastas == 6) {
		Pasta* pasta = new Lasagna_Especial();
		builder->agregarPasta(pasta);
		cout << "Se agrego Lasagna Especial de la Casa al pedido! Presione Enter para continuar...";
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
	} while (op_eliminar != 0);

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

Boleta* SistemaOrdenes::confirmar(info us) {

	Orden orden = builder->obtenerOrden();
	//Boleta* boleta = new Boleta(us, orden.pizzas, orden.pastas, orden.bebidas, orden.postres, orden.total);
	Boleta* boleta = new Boleta(us, orden);
	cout << "CONFIRMACION DE ORDEN" << endl << endl;
	cout << "Procesando orden..." << endl;
	cout << "Se confirmo la orden de venta!!!" << endl << endl;
	boleta->mostrar(); cout << endl;
	cout << "Presione Enter para continuar...";
	cin.ignore(); cin.get(); system("cls");

	return boleta;

}

void SistemaOrdenes::mostrarOrden() {

	cout << "DETALLES DEL PEDIDO ACTUAL" << endl << endl;
	builder->mostrar(); cout << endl;
	cout << "Presione Enter para continuar...";
	cin.ignore(); cin.get(); system("cls");
}
