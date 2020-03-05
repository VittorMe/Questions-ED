#include <iostream>
using namespace std;


typedef unsigned long long int myint;

myint fib (myint n  ){
    if (n < 1 ){
        try {
            if (n == 0 ) throw 1;
        } catch(int erro ){
            if (erro ==1 ) cout<< "ERRO"<<endl;
        }

    } else if( n < 3 ){
        return 1 ;
    } else 
        return fib(n -1) + fib( n -2);
}

int main (){
    myint a;
    cin >> a;
    cout << fib(a)<<endl;
    return 0;
}