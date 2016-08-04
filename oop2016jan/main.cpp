#include "slika.h"
#include "boja.h"
#include <iostream>
#include "crno_bela.h"
#include "galerija.h"
#include "invertor.h"
#include "siva.h"

int main() {
	try {
		Slika s1(1, 1); 
		CrnoBela cb(1, 1);
		Siva s(1, 1);
		Galerija g;
		s1.posBoja(Boja(50, 20, 200), 0, 0);
		cb.posBoja(Boja(0, 0, 0), 0, 0);
		s.posBoja(Boja(100, 100, 100), 0, 0);
		((g += s1) += cb) += s;
		cout << g; Invertor i; i.filter(g);
		cout << g;
		system("pause");
	}
	catch (GIndeks& g) { cout << g; }
	catch (GBoja& g) { cout << g; }
	catch (...) {}
	return 0;}