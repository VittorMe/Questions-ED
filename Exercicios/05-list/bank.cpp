#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

struct Cliente{
    string nome;
    int doc;
    int paciencia;

    Cliente(string id = " ", int doc = 0, int paciencia = 0) :     nome(id), doc(doc), paciencia(paciencia){ }

    string str() {
		return nome + ":" + to_string(doc) + ":" + to_string( paciencia);
	}

    bool possuiDoc(){
        return doc > 0;
    }

    bool possuiPaciente(){
        return paciencia > 0;
   }
};

struct Banco{
    vector<Cliente*> caixas;
    list<Cliente*> filaEntrada;
    list<Cliente*> filaSaida;
    int docsEntregue{0};
    int docsPerdidos{0};
    int tics{0};

    Banco(int caixas) {
       this->caixas = vector<Cliente*>(caixas);
    }

     void insert(Cliente* cliente)
    {
        this->filaEntrada.push_front(cliente);
    }

    bool verificaVazio()
    {
        return caixas.size() > 0;
    }

    bool entradaVazia(){
        return filaEntrada.size() >0;
    }

    bool saidaVazia(){
        return filaSaida.size() > 0;
    }

    void tic()
    {
        if ( !saidaVazia() )
        {
            for (auto it = this->filaSaida.begin(), end = this->filaSaida.end(); it != end; it++)
            {
                this->filaSaida.erase(it);
            }
        }

        if ( !verificaVazio() )
        {
            for (auto it = this->caixas.begin(), end = this->caixas.end(); it != end; it++)
            {
                Cliente *cliente = *it;
                if (cliente->possuiDoc())
                    docsEntregue = cliente->doc;
                else
                {
                    this->filaSaida.push_back(*it);
                    this->caixas.erase(it);
                }
            }
        }
        else{
            if(this->entradaVazia()){
                 for (auto it = this->filaEntrada.begin(), end = this->filaEntrada.end(); it != end; it++)
                {
                    this->caixas.push_back(*it);
                }
            }
        }
        if (!this->entradaVazia()){
            for (auto it = this->filaEntrada.begin(), end = this->filaEntrada.end(); it != end; it++){
                Cliente *cliente = *it;
                if (cliente->possuiPaciente())
                    cliente->paciencia--;
                else
                {
                    this->filaSaida.push_back(cliente);
                    this->filaEntrada.erase(it);
                }
                        
             }
        }
    }
    void show()
    {
        for (auto cliente: this->caixas)
            cout << "[" << (cliente == nullptr ? "" : cliente->str()) << "]";

        cout << "\nna fila de entrada :{ ";
        for (auto fila: this->filaEntrada)
            cout << fila->str() << " ";
        cout << "}";

        cout << "\nna fila de saida :{ ";
        for (auto fila : this->filaSaida)
            cout << fila->str() << " ";
        
        cout << "}\n";

    }
};

int main(){
    Banco banco(2);
    while(true){
        string linha, command;
        getline(cin, linha);
        cout << "$" << linha << endl;

        stringstream ss(linha);
        ss >> command;

        if (command == "end") break;

        if (command == "show")
            banco.show();

        else if (command == "in")
        {
            string nome;
            int quantidadeDocumentos {0};
            int paciencia {0};
            ss >> nome >> quantidadeDocumentos >> paciencia;
            banco.insert(new Cliente(nome, quantidadeDocumentos, paciencia));
        }

        else if (command == "init")
        {
            int quantidadeCaixas {0};
            ss >> quantidadeCaixas;
            banco = Banco(quantidadeCaixas);
        }

        else if (command == "tic")
        {
            banco.tic();
        }

        else if (command == "finish")
        {
            while(!banco.saidaVazia())
                banco.tic();
            
            cout << "recebido: " << banco.docsEntregue << endl;
            cout << "perdidos: " << banco.docsPerdidos - 1 << endl;
            cout << "tics: " << banco.tics << endl;
        }

        else cout << "fail: comando invalido" << endl;
    }
    return 0;
}