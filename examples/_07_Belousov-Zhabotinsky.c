#include <collinion.h>

DECLARE_TYPE:	healthy;
DECLARE_TYPE:	ill;
/*
https://www.hermetic
      //
The Belousov

(i) If the cell is healthy (i.e., in state 0) then its new state is [a/k1] + [b/k2], where a is the number of infected cells among its eight neighbors, b is the number of ill cells among its neighbors, and k1 and k2 are constants. Here "[]" means the integer part of the number enclosed, so that, for example, [7/3] = [2+1/3] = 2.
(ii) If the cell is ill (i.e., in state n) then it miraculously becomes healthy (i.e., its state becomes 0).
(iii) If the cell is infected (i.e., in a state other than 0 and n) then its new state is [s/(a+b+1)] + g, where a and b are as above, s is the sum of the states of the cell and of its neighbors and g is a constant.
*/
SET_COLORS
	CELL_COLOR[healthy] = WHITE;
	CELL_COLOR[ill] = GREEN;
	CELL_COLOR[DEFAULT_COLOR] = RED;
END

PRIME_ALGO
	int a;
	int b;
	int k1 = 5;
	int k2 = 3;
	int g =  4;
	int s = k1 + k2 + CELL;
	a = 0;
	/* infected cell are all above cell_type 'ill'
	 * lets hope there is no infected cells above 100
	 * the higher is the value, the more your computer will nee cumputing */
	int lowest_infected_value = ill + 1;
	for (int i = lowest_infected_value ; i < 100 ; i++) {
		a += NB_AROUND(i);
	}
	b = NB_AROUND(ill);
switch(CELL) {
	case healthy:
		NEW_CELL = a / k1 + b / k2;
		break ;
	case ill:
		NEW_CELL = healthy;
		break ;
	default: // infected
		NEW_CELL = s / (a + b + 1) + g;
		break;
}
END_ALGO

ALGO
END_ALGO
