#include "Selector.h"
Selector::Selector(int N) {

    int LN = N;
    std::vector<int> select_data[2];
    if (LN == 1)
    {
        sdata = select_data[0] = { 1 };
    }
    else  if(LN == 2)
    { 
        sdata = select_data[0] = {1,2,1};
    }
    else if (LN == 3) { select_data[0] = { 1,2,1,3,1,2,1 }; }
    else {
        for (int i = 4; i < LN + 1; i++) {
            select_data[1].insert(select_data[1].end(), select_data[0].begin(), select_data[0].end());
            select_data[1].push_back(i);
            select_data[1].insert(select_data[1].end(), select_data[0].begin(), select_data[0].end());

            select_data[0].clear();
            sdata = select_data[0] = select_data[1];
            select_data[1].clear();
            }
        }

    for (auto v : select_data[0]) {
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