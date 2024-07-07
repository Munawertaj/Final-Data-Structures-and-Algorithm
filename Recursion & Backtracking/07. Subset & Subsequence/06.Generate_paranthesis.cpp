#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Function to generate all valid parentheses using recursion
void generateParanthesis(string& paranthesis, int open, int close, vector<string>& allValidParanthesis) {
    // Base case: when no more open or close parentheses left to add
    if(open == 0 && close == 0) {
        allValidParanthesis.push_back(paranthesis);  // Add the current combination to the result
        return;
    }

    // If there are open parentheses left to add
    if(open > 0) {
        paranthesis.push_back('(');
        generateParanthesis(paranthesis, open - 1, close, allValidParanthesis);
        paranthesis.pop_back();  // Backtrack to explore other combinations
    }

    // Ensuring closing parentheses are less than or equal to opening ones
    if(close > open) {
        paranthesis.push_back(')');
        generateParanthesis(paranthesis, open, close - 1, allValidParanthesis);
        paranthesis.pop_back();  // Backtrack to explore other combinations
    }
}

// Function to generate all valid parentheses and return the result vector
vector<string> generateParanthesis2(string& paranthesis, int open, int close, vector<string>& allValidParanthesis) {
    // Base case: when no more open or close parentheses left to add
    if(open == 0 && close == 0) {
        allValidParanthesis.push_back(paranthesis);  // Add the current combination to the result
        return allValidParanthesis;
    }

    // If there are open parentheses left to add
    if(open > 0) {
        paranthesis.push_back('(');
        allValidParanthesis = generateParanthesis2(paranthesis, open - 1, close, allValidParanthesis);
        paranthesis.pop_back();  // Backtrack to explore other combinations
    }

    // Ensuring closing parentheses are more than or equal to opening ones
    if(close > open) {
        paranthesis.push_back(')');
        allValidParanthesis = generateParanthesis2(paranthesis, open, close - 1, allValidParanthesis);
        paranthesis.pop_back();  // Backtrack to explore other combinations
    }

    return allValidParanthesis;  // Return the accumulated results
}

// Function to generate all valid parentheses and return the result directly
vector<string> generateParanthesis3(string& paranthesis, int open, int close) {
    // Base case: when no more open or close parentheses left to add
    if(open == 0 && close == 0) {
        return {paranthesis};  // Return the current valid combination
    }

    vector<string> ansFromLeft, ansFromRight;

    // If there are open parentheses left to add
    if(open > 0) {
        paranthesis.push_back('(');
        ansFromLeft = generateParanthesis3(paranthesis, open - 1, close);
        paranthesis.pop_back();  // Backtrack to explore other combinations
    }

    // Ensuring closing parentheses are more than or equal to opening ones
    if(close > open) {
        paranthesis.push_back(')');
        ansFromRight = generateParanthesis3(paranthesis, open, close - 1);
        paranthesis.pop_back();  // Backtrack to explore other combinations
    }

    // Combine the results from both recursive calls
    ansFromLeft.insert(ansFromLeft.end(), ansFromRight.begin(), ansFromRight.end());  
    return ansFromLeft;  // Return the combined results
}

// Function to print all generated parentheses
void printAllValidParanthesis(vector<string>& allValidParanthesis) {
    for(auto& paranthesis: allValidParanthesis) {
        for(char ch: paranthesis) {
            cout << ch;
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int total = 3;  // Number of bracket pairs
    vector<string> allValidParanthesis;
    string paranthesis = "";
    
    // generateParanthesis(paranthesis, total, total, allValidParanthesis);
    allValidParanthesis = generateParanthesis2(paranthesis, total, total, allValidParanthesis);
    // allValidParanthesis = generateParanthesis3(paranthesis, total, total);

    printAllValidParanthesis(allValidParanthesis);

    return 0;
}
