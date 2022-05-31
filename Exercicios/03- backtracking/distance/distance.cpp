#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool inserir(string& linha, int index, int limite, int valor) {
    for(int i {index - limite}; i < index + limite + 1; i++ )
        if(linha[i] == valor)
            return false;
    return true;
}

bool preenche(string& linha, int index, int limite) {
    if((int) linha.size() == index)
        return true;

    if(linha[index] != '.')
        return preenche(linha, index + 1, limite);

    for(char valor {'0'}; valor <= limite + '0'; valor++) {
        if(inserir(linha, index, limite, valor)) {
            linha[index] = valor;
            cout << linha << endl;

            if(preenche(linha, index + 1, limite))
                return true;
        }
    }

    linha[index] = '.';
    cout << linha << endl;

    return false;
}


int main(){
    string linha{};
    int prox{};
    cin >> linha>> prox;
    cin.ignore();
    cout<< endl;

    preenche(linha, 0 , prox);
}