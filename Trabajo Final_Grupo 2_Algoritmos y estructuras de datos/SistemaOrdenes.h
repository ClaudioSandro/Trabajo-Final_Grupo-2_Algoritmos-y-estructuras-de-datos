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
	int opcionPostres();
	int opcionEliminarTipo(string tipo);

	void agregarPizza();
	void agregarPasta();
	void agregarBebida();
	void agregarPostre();
	void eliminarTipo(string tipo);

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
	Bebida* x;
	cout << "SELECCIONE LA BEBIDA QUE DESEA AGREGAR" << endl << endl;
	x = new CocaCola();
	cout << "1. Coca Cola 1.5L S/" << x->getPrecio() << endl;
	x = new IncaCola();
	cout << "2. Inca Cola 1.5L S/" << x->getPrecio() << endl;
	x = new Sprite();
	cout << "3. Sprite Personal S/" << x->getPrecio() << endl;
	x = new Fanta();
	cout << "4. Fanta Personal S/" << x->getPrecio() << endl;
	x = new AguaMineral();
	cout << "5. Agua personal S/" << x->getPrecio() << endl;
	
	cout << "0. Volver" << endl << endl;
	cout << "Opcion: "; cin >> op; cout << endl;

	delete x;
	return op;
}

int SistemaOrdenes::opcionPostres() {
	int op;
	Postre* x;
	cout << "SELECCIONE EL POSTRE QUE DESEA AGREGAR" << endl << endl;
	x = new Pizza_de_chocolate();
	cout << "1. Pizza de Chocolate S/" << x->getPrecio() << endl;
	x = new Churro_D_ITALIA();
	cout << "2. Churro d'Italia (4 un) S/" << x->getPrecio() << endl;
	x = new Rolls_De_Manajar();
	cout << "3. Rolls de Manjar (6 un) S/" << x->getPrecio() << endl;
	x = new Volcan_De_Chocolate();
	cout << "4. Volcan de Chocolate S/" << x->getPrecio() << endl;
	
	cout << "0. Volver" << endl << endl;
	cout << "Opcion: "; cin >> op; cout << endl;

	delete x;
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

	
}

void SistemaOrdenes::agregarPizza() {

	int opPizzas = opcionPizzas();

	if (opPizzas == 1) {
		Pizza* pizza = new Americana();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Americana al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPizzas == 2) {
		Pizza* pizza = new Hawaiana();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Hawaiana al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPizzas == 3) {
		Pizza* pizza = new Mozzarela();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Mozzarela al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPizzas == 4) {
		Pizza* pizza = new Pepperoni();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Pepperoni al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPizzas == 5) {
		Pizza* pizza = new Vegetariana();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Vegetariana al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPizzas == 6) {
		Pizza* pizza = new Suprema();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Suprema al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPizzas == 7) {
		Pizza* pizza = new Barbacoa();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Barbacoa al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get();
	}
	if (opPizzas == 8) {
		Pizza* pizza = new Calzone();
		builder->agregarPizza(pizza);
		cout << "Se agrego Pizza Calzone al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	system("cls");
}

void SistemaOrdenes::agregarPasta() {

	int opPastas = opcionPastas();

	if (opPastas == 1) {
		Pasta* pasta = new Spaghetti_a_lo_Alfredo();
		builder->agregarPasta(pasta);
		cout << "Se agrego Spaghetti a lo Alfredo al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPastas == 2) {
		Pasta* pasta = new Pasta_Puttanesca();
		builder->agregarPasta(pasta);
		cout << "Se agrego Pasta Puttanesca al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPastas == 3) {
		Pasta* pasta = new Tallarines_y_Champinones();
		builder->agregarPasta(pasta);
		cout << "Se agrego Tallarines en Salsa Blanca y Mushrooms al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPastas == 4) {
		Pasta* pasta = new Raviolis();
		builder->agregarPasta(pasta);
		cout << "Se agrego Raviolis al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPastas == 5) {
		Pasta* pasta = new Lasagna_Original();
		builder->agregarPasta(pasta);
		cout << "Se agrego Lasagna Original Italiana al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get();
	}
	if (opPastas == 6) {
		Pasta* pasta = new Lasagna_Especial();
		builder->agregarPasta(pasta);
		cout << "Se agrego Lasagna Especial de la Casa al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	system("cls");
}

void SistemaOrdenes::agregarBebida() {

	int opBebidas = opcionBebidas();

	if (opBebidas == 1) {
		Bebida* bebida = new CocaCola();
		builder->agregarBebida(bebida);
		cout << "Se agrego Coca Cola al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opBebidas == 2) {
		Bebida* bebida = new IncaCola();
		builder->agregarBebida(bebida);
		cout << "Se agrego Inca Cola Puttanesca al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opBebidas == 3) {
		Bebida* bebida = new Sprite();
		builder->agregarBebida(bebida);
		cout << "Se agrego Sprite al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get();
	}
	if (opBebidas == 4) {
		Bebida* bebida = new Fanta();
		builder->agregarBebida(bebida);
		cout << "Se agrego Fanta al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opBebidas == 5) {
		Bebida* bebida = new AguaMineral();
		builder->agregarBebida(bebida);
		cout << "Se agrego Agua Mineral al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	system("cls");
}

void SistemaOrdenes::agregarPostre() {

	int opPostres = opcionPostres();

	if (opPostres == 1) {
		Postre* postre = new Pizza_de_chocolate();
		builder->agregarPostre(postre);
		cout << "Se agrego Pizza de Chocolate al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPostres == 2) {
		Postre* postre = new Churro_D_ITALIA();
		builder->agregarPostre(postre);
		cout << "Se agrego Churro d'Italia al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get();
	}
	if (opPostres == 3) {
		Postre* postre = new Rolls_De_Manajar();
		builder->agregarPostre(postre);
		cout << "Se agrego Rolls de Manjar al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	if (opPostres == 4) {
		Postre* postre = new Volcan_De_Chocolate();
		builder->agregarPostre(postre);
		cout << "Se agrego Volcan de Chocolate al pedido! Presione Enter para continuar...";
		cin.ignore(); cin.get(); 
	}
	system("cls");

}

void SistemaOrdenes::eliminar() {
	int op_eliminar;
	do {
		op_eliminar = opcionEliminar();

		switch (op_eliminar)
		{
		case 1: eliminarTipo("pizza"); break;
		case 2: eliminarTipo("pasta"); break;
		case 3: eliminarTipo("bebida"); break;
		case 4: eliminarTipo("postre"); break;
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

	if (tipo == "pasta") {
		int op;
		do {
			op = opcionEliminarTipo(tipo);
			if (op != 0) {
				builder->eliminarPasta(op - 1);
				cout << "Se elimino la pasta en la posicion " << op << "...Presione Enter para continuar...";
				cin.ignore(); cin.get();
				system("cls");
			}
		} while (op != 0);
	}

	if (tipo == "bebida") {
		int op;
		do {
			op = opcionEliminarTipo(tipo);
			if (op != 0) {
				builder->eliminarBebida(op - 1);
				cout << "Se elimino la bebida en la posicion " << op << "...Presione Enter para continuar...";
				cin.ignore(); cin.get();
				system("cls");
			}
		} while (op != 0);
	}

	if (tipo == "postre") {
		int op;
		do {
			op = opcionEliminarTipo(tipo);
			if (op != 0) {
				builder->eliminarPostre(op - 1);
				cout << "Se elimino la bebida en la posicion " << op << "...Presione Enter para continuar...";
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
