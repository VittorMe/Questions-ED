#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void show (vector <string> &mato){
    for(auto line : mato ){
        cout << line << endl;
    }
}

void burn (vector <string> &mato, int lp, int cp){
    int numeroLinhas = mato.size();
    int numeroColunas = mato[0].size();

    if(lp >= numeroLinhas || cp >= numeroColunas || lp < 0 || cp < 0)
        return;
    else if (mato[lp][cp] != '#') 
        return;

    mato[lp][cp] = 'o';
    burn(mato, lp -1, cp);
    burn(mato, lp +1, cp);
    burn(mato, lp, cp - 1);
    burn(mato, lp, cp + 1);
}



int main(){
    int n_linhas, n_colunas, l_fogo, c_fogo;
    cin >> n_linhas >> n_colunas >> l_fogo >> c_fogo;
    
    vector<string> map (n_linhas);

    for(int i = 0 ; i < n_linhas; i++ ){
        cin >> map [i];
    }

    burn (map, l_fogo, c_fogo);
    show(map);
}

