#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Lista {
	void brisi();
protected:
	struct Elem {
		T pod; Elem* sled;
		Elem(const T& p, Elem* s = nullptr) {
			pod = p; sled = s;
		}
	};
	Elem *prvi, *posl;
public:
	Lista() { prvi = posl = nullptr; }
	Lista(const Lista &lst) = delete;
	~Lista() { brisi(); }
	Lista& operator=(const Lista &lst)
		= delete;
	Lista& operator+=(const T& t) {
		posl = (!prvi ? prvi : posl->sled) =
			new Elem(t);
		return *this;
	}
	template<typename U>
	friend ostream& operator<<(ostream& it, const Lista<U>& z) {
		for (Elem* tek = z.prvi; tek;
			tek = tek->sled)
			it << tek->pod << endl;
		return it;
	}

};

template <typename T>
void Lista<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi; prvi = prvi->sled;
		delete stari;
	}
	posl = nullptr;
}
