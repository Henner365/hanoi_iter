#pragma once
#include <vector>
#include <iostream>

/*
create a selector type.

who produce the string of numbers

moves F, I in relation to rings N.

K = 2.
F(0)=0 ; F(N) = F(N-1) *2 +1. Or 2^N -1 .
Selector sequence to be constructed. Consist of array med length 2^N-1.
 n = 0. x are sequences.


SUM ( K ,  n= 0  -> N-3. )

K = x(n)
x(n), K= K+1, x(n) =  x(++n);
.
.
.
.
 x(n), N, x(n) = x(++n); n = N-3;

until K = N.
F makes integer sequense 1 , 3 , 7,  15, 31, 63,127,255 … etc etc .

example. N = 7.
K             = x[0]
x[0],K+1,x[0] = x[1]
x[1],K+2,x[1] = x[2]
x[2],K+3,x[2] = x[3]
x[3],K+4,x[3] = x[4]
x[4],K+5,x[4] = x[5]


*/


class Selector
{
private:
	std::vector<int> sdata;
	int pos = 0;
public:
	Selector(int N);
	int first();
	int next();

};

