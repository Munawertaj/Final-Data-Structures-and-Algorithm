#include<iostream>
using namespace std;

int sumOfDigits(int num) {

    if(num < 10)
        return num;
    
    int rem = num % 10;
    return rem + sumOfDigits(num / 10);
}

int main() {
    int num = 1234567;

    cout << sumOfDigits(num);
}