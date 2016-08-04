#pragma once
#include "element.h"
#include "boja.h"
#include "galerija.h"

class Filter {
public:
	virtual void obrada(Element& el)
		const = 0;                       // ovo znaci da je klasa apstraktna
	void filter(Galerija& g) const;
};
void Filter::filter(Galerija& g) const {
	Galerija::Elem* tek;
	for (tek = g.prvi; tek; tek = tek->sled)
		for (int i = 0; i<tek->pod.v(); i++)
			for (int j = 0; j<tek->pod.k(); j++)
				obrada(tek->pod(i, j)); // pod(i,j) je objekat tipa Element
}