#pragma once
#include <list>

// holds 2 linked lists. representing each recursive function.

template <class T>
class structure
{
private:
        int size;

        T* BrachPointer;
        T* ActualPointer;

        std::list<T> A_list;
        std::list<T> B_list;
       
        
public:
    structure(int iv) {





        }
    void RotateA();
    void RotateB();



        


};

