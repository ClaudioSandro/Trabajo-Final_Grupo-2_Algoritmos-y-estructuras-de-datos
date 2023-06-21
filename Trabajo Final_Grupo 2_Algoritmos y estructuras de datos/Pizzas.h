#pragma once
#include "ProductosPadre.h"

class Americana : public Pizza {
public:
	Americana() : Pizza("Pizza Americana", 26.90) {}
};

class Hawaiana : public Pizza {
public:
	Hawaiana() : Pizza("Pizza Hawaiana", 32.90) {}
};

class Mozzarela : public Pizza {
public:
	Mozzarela() : Pizza("Pizza Mozzarela", 29.90) {}
};

class Pepperoni : public Pizza {
public:
	Pepperoni() : Pizza("Pizza Pepperoni", 32.90) {}
};

class Vegetariana : public Pizza {
public:
	Vegetariana() : Pizza("Pizza Vegetariana", 36.90) {}
};

class Suprema : public Pizza {
public:
	Suprema() : Pizza("Pizza Suprema", 39.90) {}
};

class Barbacoa : public Pizza {
public:
	Barbacoa() : Pizza("Pizza Barbacoa", 38.90) {}
};

class Calzone : public Pizza {
public:
	Calzone() : Pizza("Calzone", 27.90) {}
};
