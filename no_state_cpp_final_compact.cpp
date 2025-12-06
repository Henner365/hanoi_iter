#include <iostream>
#include<cmath>
int main()
{
// solution for from A -> C and A -> B all in one with a for loop.
// change atoc to false to get A -> B movement. True to get A -> C.
// choose any positive integer N odd or EVEN.

bool atoc=true;//= true  atoc true means A->C. atoc false means A -> B
int nActual{0},frompole,topole;
int N=3;int v=0;
 
// int sq[]{2,1,3} or |1,2,3}
int sq[]{( 1 + (1 + N%2)%2),(1 +N%2),3};
int n = std::pow(2,N)-1;

	for ( nActual = 1; nActual<= n;nActual++){
	v=frompole=( (nActual&(nActual-1))*(1+N%2))%3;
	if(atoc && frompole >0 )v=(1+frompole%2);
					std::cout<<"from : "<<v<<"\n";
	v= topole=(sq[(nActual-1)%3]-frompole);//  rely on frompole
    if(atoc && topole>0)v=((topole%2)+1);
                  	std::cout<<" to :\t\t\t "<<v<<"\n";} 
	
return 0;
}



