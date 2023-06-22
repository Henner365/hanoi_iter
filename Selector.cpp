#include "Selector.h"
Selector::Selector(int N) {

    int LN = N;
    std::vector<int> select_data,select_add;
    if (LN == 1)
    {
        sdata = select_data = { 1 };
    }
    else  if(LN == 2)
    { 
        sdata = select_data = {1,2,1};
    }
    else if (LN == 3) { select_data = { 1,2,1,3,1,2,1 }; }
    else {
        select_data = { 1,2,1,3,1,2,1 };
        for (int i = 4; i < (LN + 1); i++) {
            select_add.insert(select_add.begin(), select_data.begin() ,select_data.end() );
            select_add.push_back(i);
            select_add.insert(select_add.end(), select_data.begin(), select_data.end());

            
                select_data.clear();
                sdata = select_data = select_add;
                select_add.clear();
                        
            }
        }

    for (auto v : select_data) {
        std::cout << v << " , ";

    }


}

int Selector::first() {
    
    pos++;
    return *(sdata.begin());
}

int Selector::next() {
    pos++;
    return sdata.at(pos);
}