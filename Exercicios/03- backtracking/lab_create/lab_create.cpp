#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
//functions
struct Posicao {
    int linha, coluna;

    Posicao(int linha, int coluna) : linha(linha), coluna(coluna) {}
};
bool pos_eh_valida(vector<string> &vet, Posicao pos) {
    int nl = vet.size();
    int nc = vet[0].size();
    auto [l, c] = pos;
    
    if (l >= nl - 1 || c >= nc - 1 || l < 1 || c < 1) 
        return false;    

    return true;
}

vector<Posicao> pegar_vizinhos(const Posicao &pos) {
    auto [l_pos, c_pos] = pos;

    return {{l_pos, c_pos - 1}, {l_pos + 1, c_pos}, {l_pos, c_pos + 1}, {l_pos - 1, c_pos}};
}

bool pode_furar(vector<string> &vet, Posicao &pos) {
    int count = 0;
    auto aux = pegar_vizinhos(pos);

    if (vet[pos.linha][pos.coluna] == ' ') 
        return false;

    for (auto [l, c] : aux) {
        if (l >= int (vet.size()) || c >= int (vet[0].size()) || l < 0 || c < 0) 
            continue;
        
        if (vet[l][c] == '#') 
            count++;  
    }

    if (count >= 3) 
        return true;
    
    return false;
}

void eliminar_parede(vector<string> &vet, Posicao &pos) {
    auto [l, c] = pos;
    
    if (!pos_eh_valida(vet, pos)) 
        return;    
    
    if (pode_furar(vet, pos)) {
        vet[l][c] = ' ';
        auto vizinhos = pegar_vizinhos(pos);
        random_shuffle(vizinhos.begin(), vizinhos.end());

        for (auto vizinho : vizinhos) 
            eliminar_parede(vet, vizinho);       
    } 
}
Posicao decide_inicio(vector<string> &vet) {
    int l_pos = rand() % (vet.size() - 2) + 1; 
    int c_pos = rand() % (vet[0].size() - 2) + 1;

    return {l_pos, c_pos};
}

void show(vector<string> &mat) {
    for(auto percorre : mat)
        cout << percorre << endl;
}
int main(){
    int linhas, colunas;
    cout << "Numero de Linhas: ";
    cin>> linhas;
    cout << "Numero de Colunas: ";
    cin>> colunas;

    vector<string> labirinto(linhas, string(colunas, '#'));

    auto inicio = decide_inicio(labirinto);

    eliminar_parede(labirinto, inicio);
    show(labirinto);
}