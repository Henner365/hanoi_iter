#include <errno.h>
#include <stack>
#include <string>
#include <iostream>


int printstack(const std::stack<int> &rss);
bool moveRing(int N, int fromPole , int moves , std::stack<int>&X,std::stack<int>&Y,std::stack<int>&Z );
bool pivot( std::stack<int>&X, std::stack<int>&Y);
bool swap(std::stack<int>&A, std::stack<int>&B);

int main(int argc, const char** argv){
int x=0,y=0;
int OnePos=1,TwoPos=1, pos=0;
int displacement=0;
int OneTwoPos=1;
int N=5;
// even or odd origin number of rings.
const int even_sequence[]={1,2,1};
const int odd_sequence[]={2,1,2};
const int *move_sequence;
bool even = true; if((N % 2)>0){even=false;};
(even)?move_sequence=&even_sequence[0]:move_sequence=&odd_sequence[0];
// game is not finished at the start.
bool two_empty_poles=false;
// inside the OneTwo sequence loop.
bool OneTwo = true;

///////////////////////////////////////////// end>

// create 3 empty stacks
std::stack<int> A,B,C;
// end create 3 empty stacks

//////////////////////////////////////// fill up >
int antal = N;
do {
A.push(antal--);
}
while (antal>0);
//////////////////////////////////////// end fill>

        //debug prints:
        std::cout<<"\n A: ";printstack(A);
        std::cout<<"\n B: ";printstack(B);
        std::cout<<"\n C: ";printstack(C);

//////////////////////////////////////// main loop

while(!two_empty_poles)
{
        x=x%3;x++; // counter 1 2 3 1 2 3 1 2 3>

        if(OneTwo){ // still inside the moving 1 2 sequence
            y=x-1;displacement= *(move_sequence + y); //pointer to next displacement;
            // determine the pole position for the next ring about to be moved.
                if(x==1 or x==3){ // If ring one is about to move. Set pos to OnePos and update OnePos position.
                pos=OnePos;
                 OnePos=(OnePos+displacement)%3;if(OnePos==0)OnePos=3; // circular movement
                }
                else // If ring two >
                { pos=TwoPos;
                  TwoPos = (TwoPos+displacement)%3;if(TwoPos==0)TwoPos=3; // circular movement
                }

                // preconditions. two_empty_poles>
                // Pos is pointing to ring to mov>
               two_empty_poles = moveRing(N,pos,displacement,A,B,C); // return true if game is finish}
                // postcondition. two_empty_poles>


                // debug purpose printout test
                std::cout<<"\n A: ";printstack(A);
        std::cout<<"\n B: ";printstack(B);
        std::cout<<"\n C: ";printstack(C);
        std::cout<<"--------------------------\n";
                // end debug purpose printout test

                                if(x==3){
                                    OneTwo=false;
                                    OneTwoPos=OnePos=TwoPos;
                                    x=0; // reset 1 2 3 counter
                                        }
                    }
          // Next move is a pivot.
          // If you are here you are out>
          // precondition. enter only if two_empt>

if(!OneTwo)
            {
                OneTwo=!OneTwo;
                switch (OneTwoPos){
                    case 1 :
                    {two_empty_poles = pivot( B,C); break;}
                    case 2 :
                    {two_empty_poles = pivot( A, C);break;}
                    case 3 :
                    {two_empty_poles = pivot( A, B);break;}

          // postcondition pivot have moved bidir>
          // depending on the pivot pattern.
                    default:
                        break;
                    };

        if(!two_empty_poles){
        std::cout<<"\n A: ";printstack(A);
        std::cout<<"\n B: ";printstack(B);
        std::cout<<"\n C: ";printstack(C);
        std::cout<<"--------------X------------\n";
        }
      }
} // end while loop

////////////////////////////////////////////// end main loop

return 0; } // end main()

int printstack(const std::stack<int> &rss){
if(!rss.empty()){ for (std::stack<int> dump = rss; !dump.empty(); dump.pop())
        std::cout << dump.top() << '\n';} else
            std::cout<<"empty\n"<<std::endl;
return 0;
}



bool moveRing(int N, int fromPole , int moves , std::stack<int>&X,std::stack<int>&Y,std::stack<int>&Z )
{
        if((int)Z.size()== N) return true; //two empty poles as all rings sits on destination C.)
      switch(fromPole){
                case 1 :
        {(moves==1)?swap(X,Y):swap(X,Z); return false;}
                case 2 :
        {(moves==1)?swap(Y,Z):swap(Y,X); return false;}
                case 3:
        {(moves==1)?swap(Z,X):swap(Z,Y); return false;}

        Default:
        break;}
return false;
}

bool pivot( std::stack<int>&X,std::stack<int>&Y)
{
    if(X.empty() && Y.empty()){
             return true;
    }else if (X.empty() && !Y.empty()){
             swap(Y,X);return false;
    }else if (!X.empty() && Y.empty()){
             swap(X,Y);return false;
    }else{
    ( Y.top() >= X.top() ) ?swap(X,Y):swap(Y,X);return false;
    }
    return false;

}

bool swap(std::stack<int>&A, std::stack<int>&B)
{
        int tmp=0;
        tmp=A.top();A.pop();B.push(tmp);
        return true;
}
