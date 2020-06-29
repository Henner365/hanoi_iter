#pragma once
#include <list>
#include <stack>
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
        std::stack<int> control;

        state* BrachPointer;
        state* ActualPointer;

        std::list<state> A_list;
        std::list<state> B_list;
       
        
public:
    structure(int iv) {



        state sta('a', 'b', 'c', iv, nullptr);
        
        
        for (int h = 0; h < iv; h++)
            control.push(1);


        for (int i = 0; i < iv; iv++)
        {
            state inp(sta.get(1),sta.get(3),sta.get(2),i, nullptr);
            A_list.push_back(inp);
        
        
        }

        for (int j = 0; j < iv; iv++)
        {
            state inp(sta.get(2), sta.get(1), sta.get(3), j, nullptr);
            B_list.push_back(inp);



        }




        }
    void RotateA();
    void RotateB();



        


};

