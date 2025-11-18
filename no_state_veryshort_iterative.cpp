#include <iostream>

// state-free solution for all positive integer numbers N. 
// an explanation to the code is here :
// https://equato.dk/hanoi_statefree.php
// see no_state_cpp_final_compact.cpp for 
// a compact A -> C , A -> B EVEN and ODD all in one solution.
//

void write_it_out(int i);

int main(int argc, char *argv[])
{
  int n,k,from,topole, seq;
  int N=4;
int sq[]{2,1,3};
int moves = (N*N)-1;
seq=0;
for ( n = 1; n<= moves;n++){
      k= (n&(n-1))%3;
      write_it_out(k);
      topole=(sq[seq]-k);
      write_it_out(topole);
      std::cout<<"*************************************************************************\n"<<std::endl;
      seq++;
      seq=seq%3;
    }
}

void write_it_out(int i){
  int k=i;
  if(k==0){std::cout<<"A\n";
  } else if(k == 1){
    std::cout<<"     B\n";
  }else
  {std::cout<<"          C\n";}
}
