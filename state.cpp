#include "state.h"


state::state(char a, char b, char c, int d,state* sp):src(a), tmp(b), dest(c), n(d) { next = sp; }
void state::fill(char a, char b, char c, int d, state* sp) {}
