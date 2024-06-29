#include<iostream>

using namespace std;

int factorial(int num)
{
    if(num < 2)
        return 1;
    
    return num * factorial(num - 1);
}

int main()
{
    for(int i = 0; i <= 10; i++)
    {
        cout << i << "! = " << factorial(i) << endl;
    }
}