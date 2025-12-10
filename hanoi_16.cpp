
#include <iostream>
#include<cmath>


struct intpair {

    int frompole{ 0 };
    int topole{ 0 };
}  ;


class funcf {
protected:
    int v{ 0 };
    intpair ret;
public:
    void set(int vv, intpair x) { v = vv;  ret.frompole = x.frompole; ret.topole = x.topole; };
    intpair operator()(int nActual, int N, bool atoc) {

        v = ret.frompole = ((nActual & (nActual - 1)) * (1 + N % 2)) % 3;
        if (atoc && ret.frompole > 0)v = (1 + ret.frompole % 2);ret.frompole = v;

        v = ret.topole = (((nActual | (nActual - 1)  )+1) * (1 + N % 2) ) % 3;
        if (atoc && ret.topole > 0)v = (1 + ret.topole % 2);ret.topole = v;

        return ret;
    };


};

int main()
{
    
    bool atoc = false;// atoc = true means A->C. atoc = false means A -> B
    int nActual{ 0 }; // frompole,topole;
    int N = 3; int v = 0;
	intpair aip; aip.frompole = 0; aip.topole = 0;
    int flyt = (int)(std::pow(2, N) - 1);
    funcf f; f.set(0 , aip);

    for (nActual = 1; nActual <= flyt; nActual++)
    {
		aip = f(nActual, N, atoc);
		std::cout << "Move disk " << nActual << " from pole " << aip.frompole << " to pole " << aip.topole << "\n";

    } 

    // what if for whatever reason we have 20 disks moving A to C  and we want 
	// to know the 102347th move only?
    nActual = 102347; N = 20; atoc = true;
	aip = f(nActual, N, atoc);
	std::cout << "The " << nActual << " move is from pole " << aip.frompole << " to pole " << aip.topole << "\n";

    return 0;
}



