#include <iostream>

using namespace std;

void print(int n) {
    if(n == 0)
        return;

    print(n - 1);

    cout << n << endl;
}

int main() {
    // write a function that takes in a number and prints it
    // print first 5 numbers: 1 2 3 4 5

    print(5);

    return 0;
}


