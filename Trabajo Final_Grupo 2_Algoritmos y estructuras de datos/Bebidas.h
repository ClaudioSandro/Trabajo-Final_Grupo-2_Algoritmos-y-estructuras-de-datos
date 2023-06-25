#pragma once
#include "ProductosPadre.h"

class AguaMineral : public Bebida {
public:
	AguaMineral() : Bebida("Agua personal", 3.00) {}
};

class CocaCola : public Bebida {
public:
	CocaCola() : Bebida("Coca Cola 1.5L", 9.50) {}
};

class IncaCola : public Bebida {
public:
	IncaCola() : Bebida("Inca Cola 1.5L", 9.50) {}
};

class Fanta : public Bebida {
public:
	Fanta() : Bebida("Fanta personal", 4.50) {}
};

class Sprite : public Bebida {
public:
	Sprite() : Bebida("Sprite personal", 4.50) {}
};





