#include "slika.h"

Slika::Slika(int v, int k, Boja b) :vrs(v),
kol(k), boja(b) {
	matrica = new Element*[vrs];
	for (int i = 0; i < vrs; i++) {
		matrica[i] = new Element[kol]; // Stvara se niz objekata Element i konstruisu se ti elementi koristeci 
										//default konstruktor klase Element (sto je kod nizova jedino moguce)
		for (int j = 0; j < kol; j++)
			matrica[i][j] = Element(boja); // Ovde se poziva podrazumevani operator dodele klase Element i kopira 
										// automatski objekat Element(boja) u element niza. Automatski el. ce biti unisten po izlasku iz ovog opsega 
	}
}
void Slika::premesti(Slika& s) {
	vrs = s.vrs; kol = s.kol; boja = s.boja;
	matrica = s.matrica; s.matrica = nullptr;
}
void Slika::brisi() {
	for (int i = 0; i < vrs; i++)
		delete matrica[i]; //delete or delete[] would probably both free the memory allocated (memory pointed), but the big difference is that delete on an array won't call the destructor of each element of the array.
	delete[]matrica;
}
void Slika::kopiraj(const Slika& s) {
	boja = s.boja;				// U tekuci objekat Boja se kopira boja slike s
	matrica = new Element*[vrs = s.vrs];
	for (int i = 0; i < vrs; i++) {
		matrica[i] = new Element[kol = s.kol];
		for (int j = 0; j < kol; j++)
			matrica[i][j] =
			Element(s.matrica[i][j]);
	}
}
ostream& operator<<(ostream& it,
	const Slika& s) {
	for (int i = 0; i < s.vrs; i++) {
		for (int j = 0; j < s.kol; j++)
			it << s.matrica[i][j] << " ";
		it << endl;
	}
	return it;
}