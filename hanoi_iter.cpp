#include <iostream>
//#include "structure.h"
#include "Selector.h"

  /*
  It allows you simulate the system stack by declaring your own stack structure and manage the recursion.
   It is accomplished as follows:

  i) Each time a recursive call is made in the algorithm, push the necessary information onto your stack.(linked list).

  ii) When you complete processing at this deeper level, pop the simulated stack frame 
  and continue processing in the higher level at the point dictated by the return address popped from the stack.

  iii) Use an iterative control structure that loops until there are no return addresses left to pop from the stack.

  h(n,source,temp,dest)
  {
  if(n>0){
      h(n-1, source,dest,temp);
      flyt source til dest;
      h(n-1, temp,source,dest)

  }

  }
    I will have 2 lists. 2 linked lists. One Alist another Blist. 
    They contain as many elements as there are rings on the left pole at start.
    if there are 3 rings. Alist contain 3 elements and Blist 3 elements.

    They represent each function in the recursive call seen above here.

    06-03-23
    was thinking on the way home from Lidl if there is a pattern in the movement direction
    Right movement , Left movement { R , L }
    distance either  1 || 2
    n = X
    X=1 {R 2}
    X=2 { R 1, R 2, R 1 }
                        Piv
    X=3 { R 2 ,R 1, L 1, R 2, L 1, R 1, R 2 }

        ->        2*R,  L,   R,   L,  2*R
                                             Piv    
    X=4 { R 1, R 2, R 1, R 1, L 2, L 1, R 1, R 2, R 1, L 1, L 2, R 1, R 1, R 2, R 1 }     
          
        ->        4*R,  2*L,  3*R,  2*L,   4*R    

        ->        X=2 seq | R, 2*L | X=2 seq | 2*L , R | X=2 seq
                                                                                     Piv    
    x=5 { R 2, R 1, L 1, R 2, L 1, R 1, R 2, R 1, L 1, L 2, L 1, L 1, R 2, R 1, L 1, R 2,
         L 1, R 1, R 2, L 1, L 1, L 2, L 1, R 1 , { X=3 sekvens }.
                
        ->       2*R,  L,   R,   L,   2*R, |  R,  4*L,  2*R,  L,  R,  L,  2*R,  4*L,  R , |  2*R,  L,  R,  L, 2*R.
                        X=3 seq                                  Piv                                   X=3 seq


        ->       X=3 seq | R, 4*L | X=3 seq | 4*L, R | X=3 seq

    x=6 ->       X=4 seq | R, 












  */


  //crtl r undo the undo





int main()
{
    int N = 5;

    Selector sl(N);
    

    int antal;
    //std::cout << "get me antal : ";
    std::cin >> antal;
    return 0;
}



