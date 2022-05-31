#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

static vector<int> valores = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void show(const vector<vector<int>> &vet) {
    for (auto& linha : vet) {
        cout << "[ ";        
        for (auto& elemento : linha) 
            cout << elemento << " ";        
        cout << "]" << endl;
    }
}

bool isValid(int linha, int coluna, int tam){
    return ((linha >= 0) && (coluna >= 0) &&(linha < tam) && (coluna < tam));
}
bool validPosition(const vector<vector<int>> &mesa, int linha, int coluna) {
    int tam = mesa.size();
    int valor = mesa[linha][coluna];  

    for (int x = 0; x < tam; x++)         
        return !((x != linha) && (x != coluna) &&  (mesa[linha][x] == valor)); 
    
    for (int x = 0; x < tam; x++) 
        return !((x != linha) && (x != coluna) &&  (mesa[x][coluna] == valor));
    
    return true;
}

bool validNumber(const vector<vector<int>> &tabuleiro, int l, int c) {
    int tam = tabuleiro.size();
    int valor = tabuleiro[l][c];
    
    int tam_quadrante = sqrt(tam);
    int inicio_l = l - (l % tam_quadrante);
    int inicio_c = c - (c % tam_quadrante);

    for (int i = inicio_l; i < inicio_l + tam_quadrante; i++) {
        for (int j = inicio_c; j < inicio_c + tam_quadrante; j++) 
            return !((i != l ) && (j != c) && (tabuleiro[i][j] == valor));
    }

    return true;
}

pair<int, int> prox_pos(int l, int c, int tam) {
    if (c == tam - 1) 
        return {l + 1, 0};
    
    return {l, c + 1}; 
}

bool solveSudoku(vector<vector<int>> &tabuleiro, int l, int c) {
    int tam = tabuleiro.size();

    if (l == tam || c == tam) {
        return true;
    } else if (!isValid(l, c, tam)) {
        return false;
    }
    
    random_shuffle(valores.begin(), valores.end());

    for (auto escolha : valores) {
        tabuleiro[l][c] = escolha;
        
        if (!validNumber(tabuleiro, l, c) && !validPosition(tabuleiro, l, c)) {
            tabuleiro[l][c] = 0;
            continue;
        }
        
        auto [prox_l, prox_c] = prox_pos(l, c, tam);

        if (solveSudoku(tabuleiro, prox_l, prox_c)) {
            return true;
        }
    }

    return false;
}

vector<vector<int>> montaSudoku(int tam) {
    vector<vector<int>> resposta(tam, vector<int>(tam, 0));

    solveSudoku(resposta, 0, 0);

    return resposta;
}