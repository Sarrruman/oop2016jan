#pragma once
#include <iostream>

using namespace std;

class GIndeks {
	friend ostream& operator<<(ostream&
		it, const GIndeks& g) {
		return it << "Indeks van opsega!";
	}
};
