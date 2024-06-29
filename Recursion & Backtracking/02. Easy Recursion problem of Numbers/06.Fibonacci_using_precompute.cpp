#include<iostream>
#include<vector>
using namespace std;

vector<int> preCompute(100, 0);

int fibo(int num) {

    if(num < 2)
        return num;
    
    if(preCompute[num])
        return preCompute[num];

    preCompute[num] = fibo(num - 1) + fibo(num - 2);
    return preCompute[num];
}

int main() {
    
    for(int i = 0; i <= 10; ++i)
    {
        cout<< fibo(i) << " ";
    }
}