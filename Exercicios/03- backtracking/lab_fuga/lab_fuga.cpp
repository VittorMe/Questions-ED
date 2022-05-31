#include <iostream>
#include <vector>
using namespace std;
//functions
void show (vector<string> &vet){
    for(auto elem : vet)
        cout<< elem<<endl;
}

void check(vector <string> &vet, pair<int,int> &inicio, pair<int, int> & final){
    for (int l = 0; l < int (vet.size() - 1); l++) {
        for (int c = 0; c < int (vet[0].size() - 1); c++) {
            if (vet[l][c] == 'I') {
                vet[l][c] = '_';
                inicio.first = l;
                inicio.second = c;
            }
            if (vet[l][c] == 'F') {
                vet[l][c] = '_';
                final.first = l;
                final.second = c;
            }
        }
    }
}


bool resolver(vector<string> & vet, int l_pos, int c_pos, pair<int, int> & final){
    int n_lin = vet.size();
    int n_col = vet[0].size();

    if (l_pos >= n_lin || c_pos >= n_col || l_pos < 0 || c_pos < 0) {
        return false;
    } else if (vet[l_pos][c_pos] == '#' || vet[l_pos][c_pos] == '.') {
        return false;
    } else if (l_pos == final.first && c_pos == final.second) {
        vet[l_pos][c_pos] = '.';
        return true;
    }

    vet[l_pos][c_pos] = '.';

    if (resolver(vet, l_pos, c_pos - 1, final)) {vet[l_pos][c_pos] = '.'; return true;}
    if (resolver(vet, l_pos + 1, c_pos, final)) {vet[l_pos][c_pos] = '.'; return true;}
    if (resolver(vet, l_pos, c_pos + 1, final)) {vet[l_pos][c_pos] = '.'; return true;}
    if (resolver(vet, l_pos - 1, c_pos, final)) {vet[l_pos][c_pos] = '.'; return true;}

    vet[l_pos][c_pos] = '_';
    return false;
}
int main(){
    int linhas, colunas;

    auto inicio = std::make_pair(0,0);
    auto final = std::make_pair(0,0);

    cin >> linhas >> colunas;
    cin.ignore();

    vector<string> labirinto(linhas);

    for(int i = 0; i < linhas; i++) {
        cin >> labirinto[i];
    }

    check(labirinto, inicio, final);
    resolver(labirinto, inicio.first, inicio.second, final);

    show(labirinto);
}