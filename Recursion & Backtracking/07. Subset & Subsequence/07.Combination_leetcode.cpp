/*
    Problem Link: https://leetcode.com/problems/permutations-ii/description/
    Problem Description: Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n]. You may return the answer in any order.
    Input: n = 4, k = 2
    Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
*/

#include<iostream>
#include<vector>
using namespace std;

void generateCombination(int total, int last, int index, vector<int> & combination, vector<vector<int>>& allCombinations) {

    if(combination.size() == total) {
        allCombinations.push_back(combination);
        return;
    }

    while(index <= last) {
        combination.push_back(index);
        index++;
        generateCombination(total, last, index, combination, allCombinations);
        combination.pop_back();
    }
}

// Function to print all generated Combinations
void showAllCombinations(vector<vector<int>>& allCombinations)
{
    cout << "{ ";
    for(auto& combination: allCombinations)
    {
        cout << "[";
        for(int val: combination)
        {
            cout << val << " ,";
        }
        cout << "], ";
    }
    cout << " }\n";
}

int main() {

    int n = 4, k = 2;

    vector<int> combination;
    vector<vector<int>> allCombinations;

    generateCombination(k, n, 1, combination, allCombinations);

    showAllCombinations(allCombinations);
}