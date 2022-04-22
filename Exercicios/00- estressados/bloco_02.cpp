#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v){
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

//Inicio Filter
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
        if(abs(v[i])> 0 && abs(v[i])< 10)
            new_v.push_back(v[i]);        
    }
    return new_v;
}

vector<int> pegar_mulheres_calmas(const vector<int>& v){
    vector<int> new_v{};
    for (int i = 0; i < (int) v.size(); i++)
    {
        if(v[i] > -10 && v[i] < 10)
            new_v.push_back(v[i]);
    }
    return new_v;
}
// Fim filter

//Inicio Acesso
vector<int> inverter_com_copia(const vector<int>& v){
    vector<int> new_v{};
    for (int i = (int)v.size() -1; i >= 0 ; i--)
    {
        new_v.push_back(v[i]);
    }
    return new_v;
    
}

void inverter_inplace(vector<int>& v){
    int size = (int)v.size()-1;
    for (int i = size, j =0; i >size/2; i--, j++)
    {
        swap(v[i],v[j]);
    }
    
}

int sortear(const vector<int>& v){
    int sorte = 0;
    sorte = v[rand()% ((int)v.size()-1)];

    return sorte;
}

void embaralhar(vector<int>& v){
    int escolhe = 0, aux=0;
    for (int i = 0; i < (int) v.size(); i++)
    {
        escolhe= (rand() % ((int)v.size()-1));
        aux = v[i];
        v[i]= v[escolhe];
        v[escolhe]= aux;
    }
    cout <<"Emabaralhar: ";
    for (int i = 0; i < (int) v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout<<endl;
}

void ordenar(vector<int>& v){
    int aux=0;
    for(int i=0; i < (int)v.size(); i++){
        for(int j=i; j < (int)v.size(); j++){
            if(v[i]>v[j]){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        } 
    }
    cout <<"Ordenar: ";
    for (int i = 0; i < (int) v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout<<endl;
}
//Fim Acesso

//Inicio Conjuntos

vector<int> exclusivos(const vector<int>& v){
    vector<int> new_v{};
    for (int i = 0; i < (int) v.size(); i++){
        int cont = 0 ;
        for (int j = i+1; j < (int)v.size(); j++){
            if(v[i] == v[j])
                cont++;
        }
        if(cont==0)
            new_v.push_back(v[i]);
    }
    return new_v;
}

vector<int> diferentes(const vector<int>& v){
    vector<int> new_v{};
     for (int i=0;i<(int)v.size();i++){
       if (find(new_v.begin(), new_v.end(), abs(v[i])) == new_v.end())
            new_v.push_back(abs(v[i]));
    }
    return new_v;
}
vector<int> abandonados(const vector<int>& v){
    vector<int> new_v{};
    for (int i=0;i<(int)v.size();i++){
        if (find(new_v.begin(), new_v.end(), v[i]== new_v.end())
            new_v.push_back(abs(v[i]));
        else
            new_v.push_back(abs(v[i]));
    }
    return new_v;
}


//Fim Conjuntos

int main(){
    int size{};
    cout << "Digite o tamanho: ";
    cin >> size;

    vector<int> vet(size);
    fillVector(vet);
    cout<<endl;

    cout<<vet <<endl;
    cout<<endl;
    cout<< "Funcoes do Filter:"<<endl;
    cout<<"Clone: "<<clonar(vet)<<endl;
    cout<< "Pegar Homens: " << pegar_homens(vet)<<endl;
    cout<< "Pegar Calmos: " << pegar_calmos(vet)<<endl;
    cout<< "Pegar Mulheres Calmas: " << pegar_calmos(vet)<<endl;

    cout<<endl<<endl;
    cout<< "Funcoes do Acesso:"<<endl;
    cout<<"Inverter com Copia: "<<inverter_com_copia(vet)<<endl;
    inverter_inplace(vet);
    cout<<"Inverter Inplace: "<<vet<<endl;
    cout<<"Sortear: "<<sortear(vet)<<endl;
    embaralhar(vet);    
    ordenar(vet);


    cout<<endl<<endl;
    cout<< "Funcoes de Conjuntos:"<<endl;
    cout<<"Exclusivos: "<<exclusivos({1, 3, 4, 3, -1, -2, -2})<<endl;//{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4, -1, -2}
    cout<<"Diferentes: "<<diferentes({1, 3, 4, 3, -1, -2, -2})<<endl;//{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4, 2}
    cout<<"Abandonados: "<<abandonados({1, 3, 4, 3, -1, -2, -2})<<endl;//{1, 3, 4, 3, -1, -2, -2} -> {3, -2}


    return 0;
}