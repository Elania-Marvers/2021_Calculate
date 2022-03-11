#include "inc.h"

int e89_get_numeral (int nbr, int mul)
{
	if (mul != 0)
		return e89_get_numeral ((nbr - (nbr % 10)) / 10, mul - 1);
	else
		return nbr % 10;

}
