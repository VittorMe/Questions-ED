#include <iostream>
#include <sstream>

using namespace std;

struct Vector{
    int capacity;
    int size;
    int *data;
};

Vector* createVector(int capacity){
    Vector* vet = new Vector();
    vet->capacity = capacity;
    vet->size = 0;
    vet->data = new int[capacity];
    return vet;
}

string show(Vector* vet) {
    std::stringstream show;

    show << "[ ";

    for (int index = 0; index < vet->size; index++) {
        show << vet->data[index] << " ";
    }

    show << "]";

    return show.str();
}
void destroyVector(Vector* vetor) {
    delete [] vetor->data;
   
    delete vetor;
}

void addVector(Vector* vet, int value){
    if(vet->size < vet->capacity){
        vet->data[vet->size]= value;
        vet->size++;
    }
}
int main(){
    string line, cmd;
    int value;
    
    Vector * vet = createVector(0);

    while(true){
        getline(cin,line);
        stringstream ss(line);
        ss >> cmd;
        if(cmd =="end"){
            break;
        }
        else if(cmd == "init"){
            ss>> value;

            if(vet != nullptr)
                destroyVector(vet);
            
            vet = createVector(value);
        } else if (cmd == "status"){
            cout << "size:" << vet->size << " capacity:" << vet->capacity << "\n";
        }else if(cmd == "add") {
            while(ss >> value)
                addVector(vet, value);
        }else if(cmd == "show") {
            cout << show(vet) << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
    destroyVector(vet);
    return 0;
}