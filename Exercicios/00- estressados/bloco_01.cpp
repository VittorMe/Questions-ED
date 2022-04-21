#include <iostream>
#include <vector>
using namespace std;

void existe(vector<int> vet, int n){
    
    int cont = 0 ;
    for (int i = 0 ; i < (int) vet.size(); i++){
        if (vet[i] == n)
            cont++;
    }
    if(cont >0)
        cout << n <<" esta na fila"<<std::endl;
    else
        cout << n <<" nao esta na fila"<<endl;
}

void contar(vector<int> vet, int n){
   int cont = 0;
   for (int i = 0 ; i < (int) vet.size(); i++){
       if (vet[i] == n)
            cont++;
   }
   cout << n <<" aparece "<< cont <<" vezes na fila" <<endl;

}

void procurar(vector<int> vet, int n){
    int cont =0;
    for(int i = 0 ; i < (int) vet.size(); i++){
        if(vet[i] == n){
            cont ++;
            cout << n <<" aparece pela primeira vez na posicao "<< (i) <<endl;
            break;
        }
    }
    if(cont == 0){
            cout << n <<" aparece pela primeira vez na posicao "<< -1 <<endl;
    }
}

void procurar_apartir(vector<int> vet, int n, int inicio){

    for(int i = inicio ; i < (int) vet.size(); i++){
        if (vet[i] == n){
            cout << n <<" aparece na posicao "<< i <<endl;
            break;

        }
    }
}


void procurar_menor(vector<int> vet){
    int menor = 0;
    for (int i = 0; i < (int) vet.size() ; i++)
    {
        if(vet[i]< vet[menor])
            menor = vet[i];
    }

    cout << menor <<std::endl;
}

void procurar_pos_menor(vector<int> vet){
    int menor = 0;
    for (int i = 0; i < (int) vet.size() ; i++){
        if(vet[i]< vet[menor])
            menor = i;
    }
    cout << menor <<endl;
}

void procurar_pos_menor_apartir(vector<int> vet, int inicio){
    int menor = 0;
    for(int i = inicio ; i < (int) vet.size(); i++){
        if(vet[i]< vet[menor])
            menor = i;
    } 
    cout << menor <<endl;   
}

void procurar_melhor_pos_se(vector<int> vet){
    int menor = -1;
    for (int i = 0; i < (int) vet.size() ; i++){
        if(vet[i]> 0 && vet[i]< vet[menor] ) 
            menor = i;
    }
    cout << menor <<endl;   
}

string mais_homens_ou_mulheres(vector<int> vet){
    int mulheres =0, homens = 0;
    for (int i = 0; i < (int) vet.size(); i++){
        if (vet[i] < 0)    
            mulheres++;
        else
            homens ++;
    }

    if(mulheres > homens)
        return"mulheres";
    else if (mulheres < homens)
        return "homens";
    else
        return "empate";
}

string mais_homens_ou_mulheres_metade(vector<int> vet){
    if ((int)vet.size() % 2 == 0){
        int soma1 = 0, soma2 = 0;
        for (int i = 0; i < ((int)vet.size()/2); i++){
            soma1 += abs(vet[i]);
        }
        for (int i = ((int)vet.size()/2); i < (int)vet.size(); i++)
        {
           soma2 += abs(vet[i]);
        }
        if(soma1 > soma2)
            return "primeira";
        else if (soma1 < soma2)
            return "segunda";
        else
            return "empate";
    }
    else{
        int soma3 = 0, soma4 = 0;
        for (int i = 0; i < (((int)vet.size()+1)/2); i++){
            soma3 += abs(vet[i]);
        }
        for (int i = (((int)vet.size()+1)/2); i < (int)vet.size(); i++)
        {
           soma4 += abs(vet[i]);
        }
        if(soma3 > soma4)
            return "primeira";
        else if (soma3 < soma4)
            return "segunda";
        else
            return "empate";
    }
}


int main (){
    //01° function
    existe({-1, -50, -99}, -1);// true
    existe({-1, -50, -99}, 10); // false

    //02° function
    contar({-1, -50, -1, -99}, -1); // 2
    contar({-1, -50, -1, -99}, 10); // 0

    //03° function
    procurar({-1, -50, -1 -99}, -50); // 1
    procurar({-1, -50, -1, -99}, 10); // -1
    
    //04° function
    procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 0); // 2
    procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 3); // 4
    procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 4); // 4

    //05° function
    procurar_menor({5, 3, -1, -50, -1, -99}); // -99
    
    //06° function
    procurar_pos_menor({5, 3, -1, -50, -1, -99}); // 5

    //07° function
    procurar_pos_menor_apartir({5, 3, -1, -50, -1, 10}, 3); // 3

    //08° function
    procurar_melhor_pos_se({5, 3, -1, -50, -1, -99}); // 1
    procurar_melhor_pos_se({-1, -50, -1, -99}); // -1

    //09° function
    cout<<mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99})<<endl; // "mulheres"
    cout<<mais_homens_ou_mulheres({5, 3, 1, -50, -1, -99})<<endl; // "empate"
    cout<<mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99})<<endl; // "homens"
    
    //10° function
    cout<< mais_homens_ou_mulheres_metade({5, 3, -1, -50, -1, -99})<<endl; // "segunda"
    cout<<mais_homens_ou_mulheres_metade({50, 98, 2, -50, -1, -99})<<endl; // "empate"
    cout<<mais_homens_ou_mulheres_metade({-51, 99, 1, -50, -1, -99})<<endl; // "primeira"

    return 0 ;
}