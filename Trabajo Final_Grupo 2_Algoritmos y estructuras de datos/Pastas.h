#pragma once
#include "ProductosPadre.h"

class Spaghetti_a_lo_Alfredo : public Pizza {
public:
	Spaghetti_a_lo_Alfredo() : Pasta("Spaghetti a lo Alfredo", 20.00) {}
};

class Pasta_Puttanesca : public Pizza {
public:
	Pasta_Puttanesca() : Pasta("Pasta Puttanesca", 19.00) {}
};

class Tallarines_y_Champinones : public Pizza {
public:
	Tallarines_y_Champinones() : Pasta("Tallarines en Salsa Blanca y Mushrooms", 20.00) {}
};

class Raviolis : public Pizza {
public:
	Raviolis() : Pasta("Raviolis", 24.90) {}
};

class Lasagna_Original : public Pizza {
public:
	Lasagna_Original() : Pasta("Lasagna Original Italiana", 28.00) {}
};

class Lasagna_Especial : public Pizza {
public:
	Lasagna_Especial() : Pasta("Lasagna Especial de la Casa", 34.00) {}
};
