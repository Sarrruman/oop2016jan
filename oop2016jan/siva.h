#pragma once
#include "boja.h"
#include "slika.h"

class Siva : public Slika {
public:
	Siva(int v = 3, int k = 4,
		Boja b = Boja()) :Slika(v, k, b) {
		if (!(b.cc() == b.zz() &&
			b.zz() == b.pp()))
			throw GBoja();
	}
	Siva& posBoja(const Boja& b, int v,
		int k) override {
		if (b.cc() == b.zz() &&
			b.zz() == b.pp())
			Slika::posBoja(b, v, k);
		return *this;
	}};