#include <iostream>
#include <list>
#include <numeric>
using namespace std;

void showList(list<int>  list, list<int>::iterator &sword){
    for (auto it = list.begin(); it!= < list.end(); it++)    
       cout<< *it << (it== );
}
    
    
}


int main(){
    int size { };
    cin >> size;
    
    int chosen {};
    cin >>  chosen;
    list<int> list(size);
    //inserindo N elementos
    iota(begin(list), end(list), 1);
    chosen -= 1;
    auto sword = next(list.begin(), chosen);

    auto fix_loop= [&list] (auto it){
        return it== list.end() ? list.begin(): it;
    };

    while(list.size() > 1){
        showList(list, *sword);
        sword =fix_loop(next(sword,1));
        sword =fix_loop(next(sword));
    }

    return 0 ;
}