#include <errno.h>
#include <stack>
#include <string>
#include  <iostream>


int printstack(const std::stack<int> &rss);
bool moveRing(int N,int fromPole , int moves  , std::stack<int>&X,std::stack<int>&Y,std::stack<int>&Z  );
bool pivot( std::stack<int>&X,  std::stack<int>&Y);

int main(int argc, const char** argv){

//////////////////////////////////////////// game start variables init

// ring 1-2-1  distances to move right. In the onetwo stack

int even_move_sequence[3]={1,2,1};
int odd_move_sequence[3]={2,1,2};

// witch pole is onetwo stack placed on.
// at the beginning of the game the rings One and Two  are both on pole 1 or A.
// Unless ofcourse there are only One ring.        

int OneTwoPos = 1; 

//  x general counter .
//  One ring position. Two ring position. actual Position
//  How far to the right will the ring have to be displaced.

int x=0;
int  OnePos=1,TwoPos=1, pos=0;
int displacement=0; 

// how many rings.        
        
int N=4; 

// even or odd origin number of rings. 

bool even = true;  if((N % 2)>0){even=false;};

// game is not finished at the start.

bool two_empty_poles=false;

// inside the OneTwo sequence loop.

bool OneTwo = true;

///////////////////////////////////////////// end game start init.



// create 3 empty stacks

std::stack<int> A,B,C;

// end create 3 empty stacks

        

//////////////////////////////////////// fill up initial left stack A with N rings

int  antal = N;
do {
A.push(antal--);
}
while (antal>0);

//////////////////////////////////////// end fill initial  left stack A with N rings


        //debug prints:
        std::cout<<"\n A: ";printstack(A);
        std::cout<<"\n B: ";printstack(B);
        std::cout<<"\n C: ";printstack(C);

        
//////////////////////////////////////// main loop

while(!two_empty_poles)
{


        x=x%3;x++; // counter 1 2 3  1 2 3  1 2 3 etc.

        if(OneTwo){ //  still inside the moving accoording to the onetwo sequence
                if(even )
                {       // if even amount of rings in the start stack
                                displacement= even_move_sequence[x-1];
                                // x-1 makes 1 2 3 into 0 1 2 the array index.
                }
                else
                {       // if odd start stack
                                displacement= odd_move_sequence[x-1];
                                 // x-1 makes 1 2 3 into 0 1 2 the array index.
                }

                // determine the pole position for the next ring about to be moved.
                if(x==1 or x==3){ // If ring one is about to be moved. Set pos to OnePos and update OnePos position.
                pos=OnePos;
                OnePos=(OnePos+displacement)%3;if(OnePos==0)OnePos=3; // circular movement
                }
                else              // If ring two is about to be moved. Set pos to TwoPos and update TwoPos position.
                { pos=TwoPos;
                  TwoPos = (TwoPos+displacement)%3;if(TwoPos==0)TwoPos=3; // circular movement
                }

                // preconditions. two_empty_poles=false, Even or odd determine displacement pattern.
                // Pos is pointing to ring to move , either 0ne or two.
                two_empty_poles = moveRing(N,pos,displacement,A,B,C); // return true if game is finish}
                // postcondition. two_empty_poles might be true. OneTwo stack moved to OneTwoPos either 1 2 or 3.


                // debug porpose printout test
                std::cout<<"\n A: ";printstack(A);
        std::cout<<"\n B: ";printstack(B);
        std::cout<<"\n C: ";printstack(C);
        std::cout<<"--------------------------\n";
                // end debug purpose printout test


                                if(x==3){OneTwo=false; // no longer inside ontwo sequence

                                        OneTwoPos=OnePos=TwoPos; // OneTwoPos = both TwoPos and OnePos after the one_two move completion.
                                        x=0; // reset 1 2 3 counter
                                        }

                    }
                                // Next move is a pivot.


                   // If you are here you are outside the onetwo move sequence, and ready to pivot.


          // precondition. enter only if two_empty_poles are not true.
            if(!OneTwo)
            {
                OneTwo=!OneTwo;
                switch (OneTwoPos){
                    case 1 :
                    {two_empty_poles = pivot( B, C);}
                    break;
                    case 2 :
                    {two_empty_poles = pivot( A, C);}
                    break;
                    case 3 :
                    {two_empty_poles = pivot( A, B);}
                    break;

          // postcondition pivot have moved bidirectional between either B-C or A-C or A-B
          // depending on the pivot pattern.
                    default:
                        break;
                    };

                  std::cout<<"\n A: ";printstack(A);
        std::cout<<"\n B: ";printstack(B);
        std::cout<<"\n C: ";printstack(C);
        std::cout<<"--------------------------\n";

            }





}

////////////////////////////////////////////// end main loop







return 0;
} // end main()



int printstack(const std::stack<int> &rss){
if(!rss.empty()){
for (std::stack<int> dump = rss; !dump.empty(); dump.pop())
        std::cout << dump.top() << '\n';}
        else
            std::cout<<"empty\n"<<std::endl;


return 0;
}



bool moveRing(int N, int fromPole , int moves  , std::stack<int>&X,std::stack<int>&Y,std::stack<int>&Z  ){


  int tmp=0;
        if((int)Z.size()== N) return true;   //two empty poles as all rings sits on destination C.)
      switch(fromPole){
                case 1 :
                     {if(moves==1){tmp = X.top();X.pop();Y.push(tmp);}
                     else
                     { tmp=X.top();X.pop();Z.push(tmp);}
                     return false;
                     }

                case 2:
                      {if(moves==1){tmp = Y.top();Y.pop();Z.push(tmp);}
                     else
                     { tmp=Y.top();Y.pop();X.push(tmp);}
                     return false;
                     }

                case 3 :
                      {if(moves==1){tmp = Z.top();Z.pop();X.push(tmp);}
                     else
                     { tmp=Z.top();Z.pop();Y.push(tmp);}
                     return false;
                     }

                 break;
        Default:

        return false;
        }
        return false;

}


// precondition.

bool pivot( std::stack<int>&X,   std::stack<int>&Y)
{

        int a=0;
        int b=0;
        switch(X.empty()){
            case true:
                switch (Y.empty()){
                    case true:
                    return true;
                    break;
                    case false:
                    b = Y.top();Y.pop();X.push(b);
                    return false;
                    break;}




            case false:
                switch (Y.empty()){
                    case true:
                    a=X.top();X.pop();Y.push(a);
                    return false;
                    break;
                    case false:
                        a=X.top();b=Y.top();
                     if(Y.top()>X.top())
                        {a=X.top();X.pop();Y.push(a);}
                    else {
                        b = Y.top();Y.pop();X.push(b);

                         }
                    break;
                    }


        default:
        return false;
        break;
        }

        return false;
}




