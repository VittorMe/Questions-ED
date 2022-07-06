#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

ostream& operator<<(ostream &os, vector<int> vet) {
    os << "[ ";
    
    for (auto i : vet) {
        os << i << " ";
    }

    os << "]";

    return os;
}

vector<int> rotaciona(vector<int> &vet, int rot,int size){
    vector<int> aux(size);
    for (int index = 0; index < size; index++) {
        int prox_pos = (index + rot) % size;
        aux.at(prox_pos) = vet.at(index);
    }

    return aux;
}
int main () { 

    int size {}, qtd {};
    
    cin>>size >> qtd;
    vector<int> vet;
   
    for(int i = 0; i < size; i++)
    {
        vet.push_back(i + 1);
    }
    cout << rotaciona(vet,qtd, size)<<endl;
    return 0;
}