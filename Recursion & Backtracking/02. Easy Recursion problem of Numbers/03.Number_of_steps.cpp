// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/
/*
    Problem Description: Given an integer num, return the number of steps to reduce it to zero.
    In one step, if the current number is even, you have to divide it by 2,
    otherwise, you have to subtract 1 from it.
*/

#include<iostream>
using namespace std;

int count(int num, int steps)
{
    if(num == 0)
        return steps;
    
    if(num & 1)
        num--;
    else
        num /=2;
        
    return count(num, steps + 1);
}

int main() {
    int num = 14;
    cout << count(num, 0);
}
