#include <iostream>
#include <list>

using namespace std;
void show(list<int>& lista, int espada){
    cout << "[ ";
    for(auto it = lista.begin(); it != lista.end(); it++)
    {
        if (*it > 0 && *it == espada)
            cout << *it << ">" << " ";
        else if (*it < 0 && *it == (-espada))
            cout << "<" << *it << " ";
        else
            cout << *it << " ";
    }
    cout << "]" << endl;
}

void iniciaList(list<int> &lista, int size, int fase){
    for(int i = 0; i < size; i++){
        lista.push_back((i + 1) * fase);
        fase *= -1;
    }
}

void kill(list<int> &list, int espada){
    auto it = list.begin();

    while (*it != espada) it++;

    if (it == list.end() && *it > 0) list.pop_front();
    else if (it == list.begin() && *it < 0) list.pop_back();
    else if (*it > 0) list.remove(*next(it));
    else if (*it < 0) list.remove(*prev(it));
}

int main(){
    int size{}, espada{}, fase{};
    cin>> size>> espada>>fase;

    list<int> list;
    iniciaList(list,size,fase);
    show(list, espada);
    return 0;

    while(list.size() > 1){
        kill(list, espada);
        espada = (espada + 1) % list.size();
    }
}