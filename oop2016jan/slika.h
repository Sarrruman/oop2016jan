#pragma once
#include "element.h"
#include "boja.h"
#include "greske.h"

class Slika {
public:
	Slika(int v = 3, int k = 4, Boja b = Boja());
	Slika(const Slika& s) { kopiraj(s); }
	Slika(Slika&& s) { premesti(s); } // s je referenca na rvrednost. An rvalue reference behaves just like an lvalue reference 
									//except that it can bind to a temporary (an rvalue). Koristi se da bi mogao da se dodeli privremeni objekat (automatski)
	~Slika() { brisi(); }
	Slika& operator=(const Slika& s) {
		if (this != &s) { brisi(); kopiraj(s); }
		return *this;
	}
	Slika& operator=(Slika&& s) {
		if (this != &s) { brisi(); premesti(s); }
		return *this;
	}
	int v() const { return vrs; }
	int k() const { return kol; }
	Element& operator()(int v, int k) {
		if (v < 0 || v >= vrs || k < 0 || k >= kol)
			throw GIndeks();
		return matrica[v][k];
	}
	const Element& operator()(int v,
		int k) const {
		return const_cast<Slika&>(*this)
			(v, k);
	}
	virtual Slika& posBoja(const Boja& b,  // oznacena kao virtual da bi mogla da se override-uje
		int v, int k) {
		(*this)(v, k).posBoja(b);
		return *this;
	}
	friend ostream& operator<<(ostream&
		it, const Slika& s);
private:
	Boja boja; 
	Element** matrica;
	int vrs, kol;
	void kopiraj(const Slika& s);
	void premesti(Slika& s); 
	void brisi();
};