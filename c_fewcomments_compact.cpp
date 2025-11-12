#include <iostream>
#include<cmath>
int main()
{

	
  bool atoc=true;// atoc true means A->C. atoc false means A -> B 
  int n{0},frompole,f,f2,topole;
  int N=4;
  f= (1+N%2); // 1 if even 2 if odd
  f2=(1+f%2); // reverse of f 
  
  // int sq[]{2,1,3} or |1,2,3}
  
  int sq[]{f2,f,3};
  int flyt = std::pow(2,N)-1;

for ( n = 1; n<= flyt;n++)
    {
    frompole=( (n&(n-1))*f)%3;
    // IF A->C adjust for A->C . swap B and C .
    if(atoc && frompole >0 ){
		frompole=(frompole%2)+1;	
      		std::cout<<"from : "<<frompole<<"\n";
    		frompole=( (n&(n-1))*f)%3;
    	    }else {
      		std::cout<<"from : "<<frompole<<"\n";}

    topole=(sq[(n-1)%3]-frompole); //
    
    if(atoc && topole>0)
	    {
		    topole=((topole%2)+1);
            	    std::cout<<" to :\t\t\t "<<topole<<"\n";
    	    }else 
	    { 
    		std::cout<<" to :\t\t\t "<<topole<<"\n";
    	    }
    } // end for
return 0;
}



