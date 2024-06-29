#include<iostream>
using namespace std;

int reverse1(int num, int ans) {

    if(num == 0)
        return ans;
    
    int rem = num % 10;
    ans = ans * 10 + rem;
    return reverse1(num / 10, ans);
}

//using helper function
int helper(int num, int ans) {

    if(num == 0)
        return ans;
    
    int rem = num % 10;
    ans = ans * 10 + rem;
    return reverse1(num / 10, ans);
}

int reverse2(int num) {
    return helper(num, 0);
}



int main() {
    int num = 1234567;
    int ans = 0;
    cout << reverse1(num, ans) << endl;
    cout << reverse2(num);
}