#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) 
{
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    
    return os;
}

//functions
void vet ( vector<int> &vetor, int pos){
    if(vetor.size()== 1){
        cout<< vetor[pos]<< endl;
        return;
    }
    if(pos == int (vetor.size() -1)){
        cout  << vetor[pos]<<endl;
        return;
    }

    cout<<vet[pos]<<endl;
    pos++;
    vet(vetor,pos);
}

void rvet(vector <int> &vet, int pos){
    if(vet.size()== 1){
        cout<< vet[pos]<< endl;
        return;
    }
    if(pos == 0 ){
        cout<< vet[pos]<< endl;
        return;
    }
    cout<< vet[pos] << " ";
    pos++;
    rvet(vet,pos);
}

int soma (vector<int> &vet, int pos){
    if(pos == int (vet.size() - 1)){
        return vet[pos];
    }
    
    return vet[pos] + soma(vet,pos +1);
}

int mult (vector<int> &vet, int pos){
    if(pos == int (vet.size() - 1))
        return vet[pos];

    return vet[pos] * mult(vet, pos+1);
}

int min (vector <int> &vet, int pos){
    if (pos == int (vet.size() -1))
        return vet[pos];
    
    auto aux = min(vet, pos +1);
    return aux < vet[pos] ?aux : vet[pos];
}

void inv(vector <int> &vet, int posInicial, int posFinal){
    if(int(vet.size() -1) / 2 == posFinal)
        return
    
    swap (vet[posInicial], vet[posFinal]);

    posFinal--;
    posInicial++;

    inv(vet,posInicial,posFinal);
}

int main(){
    string line{};
    cin>> line;
    stringstream ss(line);

    vector <int> vetor{};
    int valor{};

    while(ss >> valor){
        vetor.push_back(valor);
    }
    cout <<endl;

    vet(vetor,0);
    rvet(vetor,int (vetor.size() -1));
    cout<< "SOMA : "<< soma(vetor, 0)<< endl;
    cout<< "MULT : "<< mult(vetor, 0)<< endl;
    cout<< "MIN : "<< min(vetor, 0)<< endl;
    inv(vetor,0,(vetor.size()-1));
    cout << "INV : " << vetor << endl;
    
}