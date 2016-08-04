#include "boja.h"

bool operator==(const Boja & b1, const Boja & b2)
{
	return (b1.c == b2.c) && (b1.z ==
		b2.z) && (b1.p == b2.p);
}
