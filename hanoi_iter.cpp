#include <iostream>
#include "structure.h"

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



  */


  //crtl r undo the undo





int main()
{

    int antal;
    std::cout << "get me antal : ";
    std::cin >> antal;
    return 0;
}



