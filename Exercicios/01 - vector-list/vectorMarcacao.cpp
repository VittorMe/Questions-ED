#include <iostream>
#include <vector>
using namespace std;


int vivos(vector<bool> vet, int sword) {
    for (int i = (sword+1); i <= (int)vet.size(); i++) {
        i = i % (int)vet.size();
        if (vet[i] == true) {
            return i;
        }
    }
    return 0;
}


void showVector(vector<bool> vet, int sword) {
    for (int i = 0; i < (int) vet.size(); i++) {
        if (i == sword%(int)vet.size()) {
            cout << vet[i] << '>';
        } else {
            cout << vet[i];
        }
        
    }  
}

int main(){
    int size{};
    cin >> size;
    
    vector<bool>vet(size, true) ;

    int sword{};
    cin >> sword;
    sword = sword - 1;
    showVector(vet, sword);
    cout<<endl;
    int qtd = size - 1;
    while(qtd--){
        

        int to_die {vivos(vet, sword)};
        vet[to_die] = false;
        sword = vivos(vet, to_die);
        showVector(vet, sword);
        cout<<endl;
    }
}