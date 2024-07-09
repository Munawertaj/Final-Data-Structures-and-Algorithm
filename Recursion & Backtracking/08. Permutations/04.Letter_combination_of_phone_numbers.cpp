// Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
/*
    Problem Description: Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

void letterCombination(int index, string& digits, string &combination, vector<string>& allCombination, unordered_map<char, string>& keys) {

    if(index == digits.size()) {
        // cout << combination << endl;
        allCombination.push_back(combination);
        return;
    }
    
    for(char ch: keys[digits[index]])
    {
        combination.push_back(ch);
        letterCombination(index + 1, digits, combination, allCombination, keys);
        combination.pop_back();
    }
}

// Function to print all generated combinations
void printAllCombinations(const vector<string>& allCombinations)
{
    for(const auto& combination: allCombinations)
    {
        for(char ch: combination)
        {
            cout << ch;
        }
        cout << ", ";
    }
    cout << endl;
}

int main() {

    string digits = "23";
    unordered_map<char, string> keys;

    keys['2'] = "abc";
    keys['3'] = "def";
    keys['4'] = "ghi";
    keys['5'] = "jkl";
    keys['6'] = "mno";
    keys['7'] = "pqrs";
    keys['8'] = "tuv";
    keys['9'] = "wxyz";
    
    string combination = "";
    vector<string> allCombination;
    
    letterCombination(0, digits, combination, allCombination, keys);

    printAllCombinations(allCombination);

    return 0;
}