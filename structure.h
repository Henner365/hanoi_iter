#pragma once
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





class structure
{
private:
        int size;
        
        std::list<state> A_list;
        std::list<state> FLL;
       
        
public:
        structure(int iv) {

        Selector select(iv);

        state sta('a', 'b', 'c', iv);
        
        
       
        // make LL A
        for (int i = 0; i < iv; iv++)
        {
            state inp(sta.get(1),sta.get(3),sta.get(2),i);
            A_list.push_back(inp);
        
        
        }




        }
    //void RotateA();
    ///void RotateB();



        


};

