#include<iostream>
using namespace std;

int fibo(int num) {

    if(num < 2)
        return num;

    return fibo(num - 1) + fibo(num - 2);
}

int main() {
    
    for(int i = 0; i <= 10; ++i)
    {
        cout<< fibo(i) << " ";
    }
}