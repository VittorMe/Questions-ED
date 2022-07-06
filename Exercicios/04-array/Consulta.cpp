#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

string show(vector<int> entrada)
{
    stringstream ss;
    for (auto elem : entrada)
    {
        ss << elem << ' ';
    }

    return ss.str();
}
vector <string> ini_vector(){

    string line{};
    int size{};
    cin>> size;
    getline(cin,line);
    stringstream ss(line);
    vector<std::string> vet(size);
    for (auto &index : vet) {
        ss >> index;
    }

    return vet;
}
vector<int> matchingStrings(vector<string> &c, vector<string> &b){
    vector<int> result;
    for (auto &elemento : c) {
        auto aux = std::count(b.begin(), b.end(), elemento);
        result.push_back(aux);
    }

    return result;
}
int main () { 

    auto con = ini_vector();
    auto entrada= ini_vector();

    cout << show(matchingStrings(con, entrada)) << endl;
    return 0;
}