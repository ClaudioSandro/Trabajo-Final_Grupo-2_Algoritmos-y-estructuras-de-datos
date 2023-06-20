#pragma once
#include "ProductosPadre.h"

class Americana : public Pizza {
public:
	Americana() : Pizza("Pizza Americana", 27.90) {}
};

class Hawaiana : public Pizza {
public:
	Hawaiana() : Pizza("Pizza Hawaiana", 32.90) {}
};