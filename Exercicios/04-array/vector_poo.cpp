#include <iostream>
#include <sstream>

using namespace std;

struct Vector{
    int capacity{0};
    int size{0};
    int *data{nullptr};

    friend ostream& operator<<(ostream &os, Vector vector){
        os << "[ ";

        for(int i = 0; i < vector.size; i++)
            os << vector.data[i] << " ";

        os << "]";
        
        return os;
    }

    Vector(int capacity) : capacity(capacity) {
        this->data = new int[capacity];
    }

    void operator = (const Vector& other){
        this->capacity = other.capacity;
        this->size = other.size;

        if(this->data != nullptr) {
            delete[] this->data;
        }

        this->data = new int[other.capacity];

        for(int i = 0; i < other.capacity; i++) {
            this->data[i] = other.data[i];
        }
    }
    ~Vector() {
        delete[] this->data;
    }

    Vector(Vector& other) {
        *this = other;
    }
    void add(int valor) {
        if(this->size < this->capacity) {
            this->data[this->size] = valor;
            capacity++;
        }
    }
};

int main(){
    string command, line;
    int valor{};
    Vector vet(4);

    while(true){
        getline(cin, line);
        stringstream ss(line);
        cin>> command;

        if(command=="end"){
            break;
        }
        else if (command =="remover"){
            ss >> valor;
            vet = Vector(valor);
        }
         else if (command == "status") {
            cout << "Tamanho: " << vet.size << " || Capacidade: " << vet.capacity << endl;
        } 
        else if (command == "adicionar") {
            while(ss >> valor)
                vet.add(valor);
        } 
        else if(command == "mostrar") {
            cout << vet << endl;
        } 
        else {
            cout << "Comando invalido!!!" << endl;
        }
    }
    return 0;
}