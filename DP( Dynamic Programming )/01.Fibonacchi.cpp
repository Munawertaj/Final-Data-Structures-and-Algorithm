#include<iostream>
#include<vector>
using namespace std;

int fibo(int n, vector<int>& results) {

    if(n < 2)
        return n;
    
    if(results[n] != -1)
        return results[n];
    
    results[n] = fibo(n - 1, results) + fibo(n - 2, results);
    return results[n];
}

int main() {

    int n = 6;
    vector<int> results(n + 1, -1);

    cout << fibo(n, results) << endl;

    return 0;
}