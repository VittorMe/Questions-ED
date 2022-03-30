#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void showVector(vector<int> &vet, int sword) {
    for (int i = 0; i < (int) vet.size(); i++) {
        if (i == sword%(int)vet.size()) 
            cout << vet[i] << '>';
        else 
            cout << vet[i];
    }  
}

void dead(vector<int> &vet, int sword) {
    vet.erase(vet.begin()+sword);
}

int main() 
{
    int size{};
    cin >> size;
    int pos{};
    cin >> pos;
    vector<int> vet(size);
    iota(begin(vet), end(vet), 1);
    pos = pos - 1;
    while ((int) vet.size() != 1) {
        showVector(vet, pos);
        pos++;
        pos = pos % (int)vet.size();
        dead(vet, pos);
        cout<<endl;
    }

    for (auto item: vet) {
        cout << item; 
    }  
}