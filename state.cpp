#include "state.h"


state::state(char a, char b, char c, int d):src(a), tmp(b), dest(c), n(d) {  }
void state::fill(char a, char b, char c, int d) {

	src = a;
	tmp = b;
	dest = c;
	n = d;

}
