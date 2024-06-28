#include <iostream>

using namespace std;

void print(int n) {
    if(n == 0)
        return;

    cout << n << endl;
    print(n - 1);
}

int main() {
    // write a function that takes in a number and prints it
    // print first 5 numbers: 5 4 3 2 1

    print(5);

    return 0;
}


