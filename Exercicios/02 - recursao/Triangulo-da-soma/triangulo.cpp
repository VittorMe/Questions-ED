#include <iostream>
#include <vector>
#include <list>

using namespace std;



void show(vector<int> triangulo){
    if((int)triangulo.size() == 0)
        return;

    cout << "[ ";
    for(int num : triangulo){
        cout << num << " ";
    }
    cout << "]" << endl;
}

vector<int> read(int size){
    vector<int> vet;
    
    for(int i = 0; i < size; i++){
        int num{};
        cin >> num;
        vet.push_back(num);
    }
    return vet;
}

void somar(vector<int>& triangulo, int size, int indice){
    if(indice == size)
        return;
    vector<int> aux;
    for(int i = 0; i < (int)triangulo.size(); i++){
        aux.push_back(triangulo[i] + triangulo[i + 1]);
    }
    aux.pop_back();
    indice++;
    show(aux);
    somar(aux, size, indice);
}

int main(){

    int size{ };
    cin >> size;
    vector<int> triangulo = read(size);

    int indice{ };
    show(triangulo);
    somar(triangulo, size, indice);
}