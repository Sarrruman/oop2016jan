#pragma once
#include "boja.h"
#include "slika.h"

extern const Boja bela = Boja(bela.MAX, // Bolje bi bilo da umesto bela.MAX stoji Boja::MAX
	bela.MAX, bela.MAX);
extern const Boja crna = Boja(crna.MIN,
	crna.MIN, crna.MIN);

class CrnoBela : public Slika {
public:
	CrnoBela(int v = 3, int k = 4,
		Boja b = Boja()) :Slika(v, k, b) {
		if (!(b == bela || b == crna))
			throw GBoja();
	}
	CrnoBela& posBoja(const Boja& b,
		int v, int k) override {
		if ((b == bela) || (b == crna))
			Slika::posBoja(b, v, k);
		return *this;
	}
};
