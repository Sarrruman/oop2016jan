#pragma once
#include "lista.h"
#include "slika.h"

class Galerija : public Lista<Slika> {
	friend class Filter;
public:
	Galerija() : Lista<Slika>() {}
};