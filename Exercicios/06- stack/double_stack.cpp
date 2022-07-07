#include <iostream>
#include <list>
#include <stack>

using namespace std;

void preenchePrateleira(stack<int> &deposito, stack<int> &prateleira){
    if(deposito.size()>0){
        for(int i = 0 ; i < deposito.size();i++){
            prateleira.push(deposito.top());
            deposito.pop();        
        }
    }
}

int main(){
    stack<int> deposito {}, prateleira {};

    int size, command, element;
    cin >> size;
    list<int> aux {};
    for(int i = 0; i<size;i++){
        cin >>command;
        switch (command)
        {
        case 1:
            cin >> element;
            deposito.push(element);
            break;
        case 2:
            if(prateleira.size()==0)
                preenchePrateleira(deposito,prateleira);

            prateleira.pop();
            break;
        case 3:
            if(prateleira.size()==0)
                preenchePrateleira(deposito,prateleira); 
            aux.push_back(prateleira.top());               
            break;
        default:
            cout << "Comamand inexistente" << endl;
            break;
        }
    }
    cout << "========" << endl;

    for (auto x : aux) {
        std::cout << x << std::endl;
    }
}