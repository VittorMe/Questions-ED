#include <iostream>
#include <list>
#include <numeric>
using namespace std;

void showList(list<int>  list, int sword){
    for(auto item: list){
        if(item == sword)
            cout<< item<< ">";
        else
            cout<< item;
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

    while(list.size() > 1){
        showList(list, *sword);
        
    }

    return 0 ;
}