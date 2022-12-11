#include <collinion.h>




SET_COLORS
	CELL_COLOR[alive] = WHITE;
	CELL_COLOR[dead] = BLACK;
END



PRIME_ALGO
END_ALGO

/*
 * https://en.wikipedia.org/wiki/Brian%27s_Brain
 */

ALGO

int	alives_around = NB_AROUND(alive);

switch(CELL) {
	case (alive):
		if ( !(alives_around == 2 || alives_around == 3) )
			NEW_CELL = dead ;
		break;
	case (dead):
		if ( alives_around == 3 )
			NEW_CELL = alive ;
		break;
	/* default is not even a must */
}
END_ALGO
