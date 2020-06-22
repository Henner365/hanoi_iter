#pragma once
class state
{
private:


    char src;
    char tmp;
    char dest;
    int n;
    state* next;

public:
    state(char a, char b, char c, int d,state* sp);

};

