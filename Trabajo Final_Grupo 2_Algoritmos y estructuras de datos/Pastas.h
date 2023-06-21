#pragma once
#include "ProductosPadre.h"

class Spaghetti_a_lo_Alfredo : public Pasta {
public:
	Spaghetti_a_lo_Alfredo() : Pasta("Spaghetti a lo Alfredo", 20.00) {}
};

class Pasta_Puttanesca : public Pasta {
public:
	Pasta_Puttanesca() : Pasta("Pasta Puttanesca", 19.00) {}
};

class Tallarines_y_Champinones : public Pasta {
public:
	Tallarines_y_Champinones() : Pasta("Tallarines en Salsa Blanca y Mushrooms", 20.00) {}
};

class Raviolis : public Pasta {
public:
	Raviolis() : Pasta("Raviolis", 24.90) {}
};

class Lasagna_Original : public Pasta {
public:
	Lasagna_Original() : Pasta("Lasagna Original Italiana", 28.00) {}
};

class Lasagna_Especial : public Pasta {
public:
	Lasagna_Especial() : Pasta("Lasagna Especial de la Casa", 34.00) {}
};
