#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) 
{
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

void fillVector(vector<int> &vet){
    for (int i = 0; i < (int) vet.size(); i++){
        cout<< "Posicao "<< i+1<<":";
        cin >> vet[i];
    }
}


vector<int> clonar(const vector<int>& v){
    vector<int> new_v{};
    for (int i = 0; i < (int)v.size(); i++)
    {
        new_v.push_back(v[i]);
    }
    return new_v;
}

vector<int> pegar_homens(const vector<int>& v){
    vector<int> new_v{};
    for (int i = 0; i < (int) v.size(); i++)
    {
        if(v[i] > 0)
            new_v.push_back(v[i]);
    }
    return new_v;    
}

vector<int> pegar_calmos(const vector<int>& v){
    vector<int> new_v{};
    for (int i = 0; i < (int) v.size(); i++)
    {
        if(abs(v[i])> 0 && abs(v[i])< 10){
            new_v.push_back(v[i]);
        }

    }
    return new_v;

}



int main(){
    int size{};
    cout << "Digite o tamanho: ";
    cin >> size;

    vector<int> vet(size);
    fillVector(vet);
    cout<<endl;

    cout<<vet <<endl;
    cout<< "Funcoes do Filter"<<endl;
    cout<<"Clone: "<<clonar(vet)<<endl;
    cout<< "Pegar Homens: " << pegar_homens(vet)<<endl;
    cout<< "Pegar Calmos: " << pegar_calmos(vet)<<endl;

    return 0;
}