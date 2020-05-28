


#include <iostream>
#include <stack>
#include <queue>

  /*
  It allows you simulate the system stack by declaring your own stack structure and manage the recursion.
   It is accomplished as follows:
  i) Each time a recursive call is made in the algorithm, push the necessary information onto your stack.

  ii) When you complete processing at this deeper level, pop the simulated stack frame 
  and continue processing in the higher level at the point dictated by the return address popped from the stack.

  iii) Use an iterative control structure that loops until there are no return addresses left to pop from the stack.

  h(n,source,temp,dest)
  {
  if(n>0){
      h(n-1, source,dest,temp);
      flyt source til dest;
      h(n-1, temp,source,dest)

  }

  }


  */

  //crtl r undo the undo

struct pair {
    int src;
    int tmp;
    int dest;
    int n;
};



class moving_pattern
{
private:
    int i, master_loop, src, tmp, dest;
    std::stack<int>  V, M, H;
    std::stack<pair> sequens;
    int stack_start_size;
    pair  a;

public:


    moving_pattern(int init) {
        stack_start_size = init;
        a.dest=0;
        a.src=0;
        a.tmp=0;
        a.n = 0;
        Vfill();
    }


    int getSize(std::stack<int> s) {
        int r;
        r = (int)s.size();
        return r;
    }

    void Vfill() {
        for (int i = stack_start_size; i > 0; i--)
            V.push(i);
    }


    std::stack<int>* ABC(int v) {
        if (v == 1) return &V;
        else if (v == 2)
            return &M;
        else
            return &H;
    }

    void start()
    {
        int betingelse = 100, loop = stack_start_size;
        std::stack<int> *t1, *t2;
        
        src = 1; 
        tmp = 2; 
        dest = 3; 
        
      
        
        if (stack_start_size == 1)
        {
            int v = V.top(); V.pop(); H.push(v);
        }
        else { // main loop start

            //a.src = src, a.tmp = tmp; a.dest = dest;


            a.n = stack_start_size;
            a.src = src;
            a.tmp = 2;
            a.dest = 3;


            while ((int)getSize(H) < stack_start_size)
            { // H is not full
                int tempo = 0;
                loop = a.n;
                switch (betingelse) {
                case 100:
                {
                    
                    while (loop > 0) {
                        //src = src, tmp = dest, dest = tmp;
                        a.src = a.src, tempo = a.tmp; a.tmp = a.dest;a.dest=tempo;  
                        sequens.push(a);
                        a.n--; loop--;
                    }
                    betingelse = 200; //skriv;

                }
                case 200:
                {
                    a = sequens.top(); sequens.pop();                      // when stack of movement order ready
                    t1 = ABC(a.src); t2 = ABC(a.dest);         // move first
                    i = t1->top(); t1->pop(); t2->push(i);
                    if (!sequens.empty()) 
                    {
                        a = sequens.top(); loop = a.n; betingelse = 100;
                    }
                    else
                    {
                        loop = a.n;
                        betingelse = 300;
                    }
                }// case 200

                case 300:
                {
                    loop = a.n;
                    while (loop > 0) { //tempo=a.src;a.src=a.tmp;a.tmp=tempo;a.dest=a.dest;
                        tempo = a.src;a.src = a.tmp; a.tmp = tempo; a.dest = a.dest; 
                        sequens.push(a);
                        a.n--; loop--;
                    }
                      betingelse = 100;


                } // case 300






                } //switch





            } // while H not full
        } // H is not full

    } // main loop end


}; // end class




int main()
{
    moving_pattern mov_p(3);
    mov_p.start();
    int antal;
    std::cout << "get me antal : ";
    std::cin >> antal;
    return 0;
}



