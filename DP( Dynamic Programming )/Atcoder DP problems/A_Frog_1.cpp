/*
    Problem Link: https://atcoder.jp/contests/dp/tasks/dp_a
    Problem Statement: There are N stones, numbered 1 through N. Each stone i (where 1 ≤ i ≤ N) has a height hi.
    A frog starts on Stone 1 and aims to reach Stone N. The frog can jump from Stone i to either Stone i+1
    or Stone i+2 any number of times. The cost incurred for each jump from Stone i to Stone j is |hi - hj|,
    where j is the stone the frog lands on.
    Find the minimum possible total cost incurred for the frog to reach Stone N.

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int jump(int index, vector<int>& height, vector<int>& cost) {
    if(index == 0) {
        return 0;
    }

    if(cost[index] != -1)
        return cost[index];

    int totalCost = INT_MAX;
    
    totalCost = min(totalCost , jump(index - 1, height, cost) + abs(height[index] - height[index - 1]));
    if(index > 1)
        totalCost = min(totalCost , jump(index - 2, height, cost) + abs(height[index] - height[index - 2]));
    
    return cost[index] = totalCost;
}

int main() {
    int stones;
    cin >> stones;

    vector<int> height(stones);
    for(int i = 0; i < stones; ++i) {
        cin >> height[i];
    }

    vector<int> cost(stones, -1);
    cout << jump(stones - 1, height, cost);
}