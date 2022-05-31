#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "functions.hpp"

using namespace std;

int main() {
    srand(std::time(0));

    auto resolution = montaSudoku(4);

    show(resolution);
}