#pragma once
#include "boja.h"
#include "element.h"
#include "filter.h"

class Invertor : public Filter {
public:
	void obrada(Element& el) const
		override {
		Boja b = Boja(b.MAX - el.b().cc(),
			b.MAX - el.b().zz(), b.MAX - el.b().pp());
		el.posBoja(b);
	}
};