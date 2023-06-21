#pragma once
#include "ProductosPadre.h"

class Pizza_de_chocolate : public Postre {
public:
	Pizza_de_chocolate() : Postre("Pizza de chocolate", 19.90) {}
};

class Churro_D_ITALIA : public Postre {
public:
	Churro_D_ITALIA() : Postre("Churro D'Italia (4 un)", 5.90) {}
};

class Rolls_De_Manajar : public Postre {
public:
	Rolls_De_Manajar() : Postre("Rolls De Manajar (6 un)", 10.90) {}
};

class Volcan_De_Chocolate : public Postre {
public:
	Volcan_De_Chocolate() : Postre("Volcan De Chocolate", 10.90) {}
};
