/*
    Problem Link: https://atcoder.jp/contests/dp/tasks/dp_b
    Problem Statement: There are N stones, numbered 1 through N. Each stone i (where 1 ≤ i ≤ N) has a height hi.
    A frog starts on Stone 1 and aims to reach Stone N. The frog can jump from Stone i to either Stone i+1, i+2, ...., i+K. The cost incurred for each jump from Stone i to Stone j is |hi - hj|, where j is the stone the frog lands on. Find the minimum possible total cost incurred for the frog to reach Stone N.

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int jump(int index, int maxJump, vector<int>& height, vector<int>& cost) {
    if(index == 0) {
        return 0;
    }

    if(cost[index] != -1)
        return cost[index];
    
    int totalCost = INT_MAX;
    for(int i = 1; i <= maxJump && index >= i; ++i) {
        
        totalCost = min(totalCost , jump(index - i, maxJump, height, cost) + abs(height[index] - height[index - i]));
    }

    return cost[index] = totalCost;
}

int main() {
    int stones, maxJump;
    cin >> stones >> maxJump;

    vector<int> height(stones);
    for(int i = 0; i < stones; ++i) {
        cin >> height[i];
    }

    vector<int> cost(stones, -1);
    cout << jump(stones - 1, maxJump, height, cost);
}