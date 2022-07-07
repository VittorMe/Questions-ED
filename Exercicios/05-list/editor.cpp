#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
void iniciar(list<char> &text, list<char>::iterator &it);
void mover_cursor_esquerda(list<char> &text, list<char>::iterator &it);
void deletar_cursor_esquerda(list<char> &text, list<char>::iterator &it);
void retornar(list<char> &text, list<char>::iterator &it);
void seguir(list<char> &text, list<char>::iterator &it);

void verifica(list<char> &entrada, list<char> &texto){
    list<char>::iterator it = texto.begin();
    for(auto element : entrada){
        if(element == 'R'){
            iniciar(texto,it);
        }
        else if(element == 'B'){
            mover_cursor_esquerda(texto,it);
        }
        else if(element == 'D'){
             deletar_cursor_esquerda(texto,it);
        }
        else if(element == '<'){
            retornar(texto, it);
        }
        else if(element == '>'){
            seguir(texto, it);
        }
        else texto.insert(it, element);
    }
    texto.insert(it,'|');
    
    
}


void iniciar(list<char> &text, list<char>::iterator &it){
    text.insert(it,'\n');
}
void mover_cursor_esquerda(list<char> &text, list<char>::iterator &it){
    if(it != text.begin()){
        it--;
        it=text.erase(it);
    }
}
void deletar_cursor_esquerda(list<char> &text, list<char>::iterator &it){
    if(it != text.end())
        it=text.erase(it);    
}

void retornar(list<char> &text, list<char>::iterator &it){
    if(it != text.begin())
        it--;    
}
void seguir(list<char> &text, list<char>::iterator &it){
    if(it != text.end())
        it++;    
}

int main() {
    string palavra{};
    list<char> entrada;
    list<char> texto;
    getline(cin, palavra);

    for(int i = 0; i < palavra.size(); i++){
        entrada.push_back(palavra[i]);
    }

    verifica(entrada,texto);

    for(auto element : texto) cout << element;
    return 0;
}