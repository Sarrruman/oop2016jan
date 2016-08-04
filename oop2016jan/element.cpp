#include "element.h"

ostream & operator<<(ostream & it, const Element & el)
{
	return it << "(" << el.boja.cc() << ","
		<< el.boja.zz() << "," << el.boja.pp() << ")";
}
