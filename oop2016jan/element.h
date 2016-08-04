#pragma once
#include "boja.h"

class Element {
public:
	Element(Boja b = Boja()) :boja(b.cc(), // Boja je automatski objekat koji se kreira na steku i koji ce biti unisten po izlasku iz opsega u kome je definisana
		b.zz(), b.pp()) {}
	Boja b() const { return boja; }
	void posBoja(const Boja& b) { boja = b; } //postavlja boju (ne kopira objekat, nego samo postavlja pokazivac na vec stvoreni)
											// b je referenca na boju, tj. unutar funkcije se ne stvara novi objekat klase Boja,
											// pa se sadrzaj objekta b kopira u njega, kako bi bilo ako bismo prosledili samo Boja b,
											// nego se prosledjuje sam objekat b koji bi u finckiji mogao da se modifikuje ukoliko bi
											// referenca bila prosledjena bez const. Ovako se postize efikasnost time sto se izbegava
											// kopiranje a osigurava se nepromenjivost objekta.
	friend ostream& operator<<(ostream & it, const Element& el);

private:
	Boja boja;
};
// NEW COMMENT IN CLASS ELEMENT