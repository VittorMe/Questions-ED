#include <iostream>
using namespace std;

int han (int n, char A, char B, char C){
    if (n == 0){
        return n;
    }else {
        han(n-1, A, C, B);
        cout << A << "->" << C << endl;
        han(n-1, B, A, C );
    }
}

int main (){
    han (3 , 'A', 'B', 'C');


    return 0;
}