#include <iostream>
#include <vector>

#include <numeric>
#include <unordered_set>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& fila) {
    os << "[ ";
    for(int i = 0; i < (int) fila.size(); i++) {
        os << fila[i];
        if(i != (int) fila.size() - 1) {
            os << ", ";
        }
    }
    os << " ]";

    return os;
}

void inicializa(vector<int>& fila, int tam) {
    for(int i = 0; i < tam; i++){
        int linha;
        cout << "Digite o elemento " << i << " : ";
        cin >> linha;
        fila.push_back(linha);
    }
}
vector<int> restanteFila(vector<int> fila, vector<int> sairam) {
    vector<int> sobraram;
    unordered_set<int> sairam_set(begin(sairam), end(sairam));

    for(auto i : fila) {
        if(sairam_set.find(i) == sairam_set.end()) {
            sobraram.push_back(i);
        }
    }

    return sobraram;
}

int main () { 
    int qtd_filaInicial{},sairam{};

    cin >> qtd_filaInicial;
    vector<int> fila(qtd_filaInicial);
    iota(begin(fila), end(fila), 1);

    cin >> sairam;
    vector<int> sairamFila(sairam);
    iota(begin(sairamFila), end(sairamFila), 1);

    cout << restanteFila(fila,sairamFila);
    return 0;
}