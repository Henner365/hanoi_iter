#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

#include <list>
#include "Selector.h"
#include "state.h"

// holds 2 linked lists. representing each recursive function.
/*h(n, source, temp, dest)
{
    if (n > 0) {
        h(n - 1, source, dest, temp);
        flyt source til dest;
        h(n - 1, temp, source, dest)

    }
*/


// A_list is default linked list representing the start situation of plates.

// FLL the final linked list contain a representation of the state of every plate.
// in a sequencial list that consist of the number of states required,  according to the initail number of plates.

// the list will then be read from start to end , to instruct the moves of plates.

class structure
{
private:
    int size = 0;


    std::list<state> A_list;
    std::list<state> FLL;


public:
    structure(int iv) :size(iv)
    {


        state sta('a', 'b', 'c', iv), input('a', 'b', 'c', 0);


        bool FLL_empty = FLL.empty();


        // make initial A_list out of sta and input.
        // if iv >=2 and even 
        // if iv >=2 and uneven

        if (iv > 1)
        {
            if (iv % 2)
            {
                for (int i = 0; i < iv; i++)
                {

                    input.fill(sta.get(1), sta.get(3), sta.get(2), i);
                    A_list.push_back(input); // put at the end of the list

                }


            }
            else
            {
                A_list.push_back(sta);
                for (int j = 1; j < iv; j++)
                {
                    input.fill(sta.get(1), sta.get(3), sta.get(2), j);
                    A_list.push_back(input);

                }

            }

        }


        //  void RotateA();
        // 
        // 
        //  void RotateB();


    }



    /*

    1.) read SK(i):
    2.) copy ALIST (sk(i)) til FLL(i) ; stop if i =2^N-1.
    3.) i++; read SK(i);
    4.) kopier ALIST(sk(i) til FLL(i) ; SWAP A , SWAP B
    5.) i++; go to 1

    */


    // create_FLL();
    void create_FLL()
    {
        int SK = 0, i = 0, stop=(size*size)-1;
        Selector SQlist(size);

        // 1.)
        while (i <= stop)
        {
            SK = SQlist.next();


            // 2.)
            std::copy_n(A_list.begin(), 1, std::back_inserter(FLL));
            if (i == stop) { i++; }
            else
            {
                // 3.)

                i++;
                SK = SQlist.next();

                // 4.)

                std::list <state>::iterator L_Iter, LPOS = A_list.begin();
                //auto begin = A_list.cbegin();
                std::advance(LPOS, SK);
                //std::copy_n(A_list.begin(), 1, std::back_inserter(FLL));
                FLL.push_back(*LPOS);
                std:advance(LPOS, -SK);

                Swap_A();
                Swap_B();
            }
        }

    }


    void Swap_A() {}

    void Swap_B() {}




};


