#pragma once
#include "ProductosPadre.h"

class Pizza_de_chocolate : public Pizza {
public:
	Pizza_de_chocolate() : Postre("Pizza de chocolate", 19.90) {}
};

class Churro_D_ITALIA : public Pizza {
public:
	Churro_D_ITALIA() : Postre("Churro D'Italia (4 un)", 5.90) {}
};

class Rolls_De_Manajar : public Pizza {
public:
	Rolls_De_Manajar() : Postre("Rolls De Manajar (6 un)", 10.90) {}
};

class Volcan_De_Chocolate : public Pizza {
public:
	Volcan_De_Chocolate() : Postre("Volcan De Chocolate", 10.90) {}
};
