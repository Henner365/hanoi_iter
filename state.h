#pragma once

// a state type 

class state
{
private:


    char src;
    char tmp;
    char dest;
    int n;
//    state* next;

public:
    state(char a, char b, char c, int d /*,state* sp*/);
    void fill(char a, char b, char c, int d/*, state* sp*/);
    char get(int i) {
        char rv='\0';

        if (i == 1) rv = 'a';
        if (i == 2) rv = 'b';
        if (i == 3) rv = 'c';
        return rv;
     }
};

