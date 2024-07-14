/*
    Problem Description: Given a dice each with 6 faces, numbered from 1 to 6, find all the combination to get Target sum. Dice can be thrown as many as you want
*/

#include<iostream>
#include<vector>
using namespace std;

void diceCombination(int totalFace, int target, vector<int>& combination, vector<vector<int>>& allCombinations) {
    
    if(target == 0) {
        allCombinations.push_back(combination);
        return;
    }

    for(int i = 1; i <= totalFace && i <= target; i++)
    {
        combination.push_back(i);
        diceCombination(totalFace, target - i, combination, allCombinations);
        combination.pop_back();
    }
}

// Function to print all generated combinations
void printAllCombinations(const vector<vector<int>>& allCombinations)
{
    for(const auto& combination: allCombinations)
    {
        cout << "[ ";
        for(int num: combination)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }
    cout << endl;
}


int main() {

    int totalFace = 6, target = 5;

    vector<int> combination;
    vector<vector<int>> allCombinations;

    diceCombination(totalFace, target, combination, allCombinations);

    printAllCombinations(allCombinations);

    return 0;
}