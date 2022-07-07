#include <iostream>
#include <list>

using namespace std;

void show(list<int> list, int pos){
    cout << "[ ";
	for(auto i = list.begin(); i != list.end(); i++){
		if(pos == 0){
			cout << *i << "> ";
		}else{
			cout << *i << ' ';
		}
		pos--;
	}
	cout << "]" << endl;
}
void kill(list<int>& list, int pos){
	auto it = list.begin();
	int walk{0};
	if(pos + 1 < (int) list.size()){
		walk = pos + 1;
	}
	advance(it, walk);
	list.erase(it);
}
void proxEspada(list<int>& list, int& pos){
	if(pos + 1 >= (int)list.size()){
		pos = 0;
	}else{
		pos++;
	}
}


void sobrevivente(list<int>& list, int pos){
    while(list.size() != 1 )
    {
        kill(list,pos);
        proxEspada(list,pos);
        show(list,pos);
    }
}
int main(){
    int tam{},pos{};
    cin>>tam>>pos;
    --pos;
    if(pos <0 || pos >= tam){
        exit(1);
    }

    list<int> list;
    for(int i = 0 ; i< tam;i++)
        list.push_back(i + 1);
    
    int aux =list.size();
   
        show(list,pos);
        sobrevivente(list,pos);
    
}