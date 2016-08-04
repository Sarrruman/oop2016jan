#pragma once

#include <iostream>
using namespace std;

class GBoja { // Klasa za greske koje se ticu boja
	friend ostream& operator<<(ostream&
		it, const GBoja& g) {
		return it << "Neispravna boja!";
	}
};

class Boja {
public:
	static const int MIN = 0, MAX = 255;

	Boja(int cc = 255, int zz = 255, int pp = 255)
	{
		if (cc<MIN || cc>MAX || zz<MIN
			|| zz>MAX || pp<MIN || pp>MAX)
			throw GBoja();
		else {
			c = cc; z = zz; p = pp;
		}
	}
	int cc() const { return c; }
	int zz() const { return z; }
	int pp() const { return p; }
	friend bool operator==(const Boja& b1, const Boja& b2);
private: 
	int c, z, p;
};