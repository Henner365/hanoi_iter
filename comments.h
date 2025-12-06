#pragma once
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
// hanoi_16.cpp : This file contains the 'main' function. Program execution begins and ends there.
// solution for both ODD and EVEN and from A -> C and A -> B all in one with a for loop.
    // change atoc to false to get A -> B movement. True to get A -> C.
    // choose any N odd or EVEN.
//  f= (1+N%2); // 1 if even 2 if odd
    //  f2=(1+f%2); // reverse of f
      // int sq[]{2,1,3} or |1,2,3}
      // int sq[]{( 1 + (1 + N%2)%2),(1 +N%2),3};
     // int sq[]{f2,f,3};
        //  frompole=( (n&(n-1))*f)%3;
          // IF A->C adjust for A->C . swap B and C .
        //  if(atoc && frompole >0 ){
              //frompole=(frompole%2)+1;
            //		std::cout<<"from : "<<(1+frompole%2)<<"\n";
              //	frompole=( (n&(n-1))*f)%3;
          //	    }else {
            //		std::cout<<"from : "<<frompole<<"\n";}
      //v=frompole=( (nActual&(nActual-1))*(1+N%2))%3;
      //if(atoc && frompole >0 )v=(1+frompole%2);
      // std::cout<<"from : "<<v<<"\n";


       //   topole=(sq[(n-1)%3]-frompole); // rely on frompole
       //v= topole=(sq[(nActual-1)%3]-frompole);

        //  if(atoc && topole>0)v=((topole%2)+1);
                //  topole=((topole%2)+1);
          //        	    std::cout<<" to :\t\t\t "<<v<<"\n";
              //   }else
      //	    {
          //		std::cout<<" to :\t\t\t "<<topole<<"\n";
              //    }

