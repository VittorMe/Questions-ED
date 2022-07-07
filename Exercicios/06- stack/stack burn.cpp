#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

struct Ponto{
    int l,c;
    Ponto(int l, int c): l(l), c(c){}
};


void show (vector <string> &map){
    cout << "======="<< endl;

    for(auto percorre : map)
        cout << percorre << endl;
}

vector<Ponto> getVizinho(Ponto p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

void burn(vector<std::string> &map, Ponto p){
    bool queimou = false;
    int n_linhas = map.size();
    int n_colunas = map[0].size();

    auto l = p.l;
    auto c = p.c;

    if (map[l][c] != '#') {
        return;
    }

    stack<Ponto> queimar {};
    map[l][c] = 'o';
    queimar.push(p);
    while(queimar.empty()){
        
        for (auto element : getVizinho(queimar.top()))
        {
           if(element.l >= n_linhas || element.c >= n_colunas || element.l < 0 || element.c < 0)
                continue;
           else if (map[element.l][element.c] == '#') {
                map[element.l][element.c] = 'o';

                queimar.push(element);

                queimou = true;

                break;
            }
        }

        if (!queimou) queimar.pop();
    }
}


int main(){
    int n_linhas, n_colunas, l_fogo, c_fogo;
    cin >> n_linhas >> n_colunas >> l_fogo >> c_fogo;
    
    vector<string> map (n_linhas);

    for(int i = 0 ; i < n_linhas; i++ ){
        cin >> map [i];
    }
    
    Ponto inicio(l_fogo, c_fogo);

    burn (map, inicio);
    show(map);
    return 0;
}