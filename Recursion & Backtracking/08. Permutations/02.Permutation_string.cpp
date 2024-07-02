#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to generate all permutations of the original string
void generatingPermutations1(int index, string& original, string processed, vector<string>& allPermutations)
{
    if(index == original.size())
    {
        allPermutations.push_back(processed);
        return;
    }

    char ch = original[index];
    int length = processed.size();

    // Insert the current character at each position in the processed string
    for(int i = 0; i <= length; ++i)
    {
        string start = processed.substr(0, i); // Substring before the insertion point
        string end = processed.substr(i, length); // Substring after the insertion point

        // Recurse with the new processed string including the current character
        generatingPermutations1(index + 1, original, start + ch + end, allPermutations);
    }
}

// Similar to generatingPermutations1 but returns the result vector
vector<string> generatingPermutations2(int index, string& original, string processed, vector<string>& allPermutations)
{
    if(index == original.size())
    {
        allPermutations.push_back(processed);
        return allPermutations;
    }

    char ch = original[index];
    int length = processed.size();

    // Insert the current character at each position in the processed string
    for(int i = 0; i <= length; ++i)
    {
        string start = processed.substr(0, i); // Substring before the insertion point
        string end = processed.substr(i, length); // Substring after the insertion point

        // Recursively generate permutations with the new processed string including the current character
        allPermutations = generatingPermutations2(index + 1, original, start + ch + end, allPermutations);
    }

    return allPermutations; // Return the accumulated permutations
}

// Function to generate permutations and return the result directly
vector<string> generatingPermutations3(int index, string& original, string processed)
{
    if(index == original.size())
    {
        return {processed};
    }

    char ch = original[index];
    int length = processed.size();

    vector<string> allPermutations;

    // Insert the current character at each position in the processed string
    for(int i = 0; i <= length; ++i)
    {
        string start = processed.substr(0, i); // Substring before the insertion point
        string end = processed.substr(i, length); // Substring after the insertion point

        // Get permutations from the recursive call
        vector<string> ansFromBelow = generatingPermutations3(index + 1, original, start + ch + end);

        // Add the new permutations to the result vector
        allPermutations.insert(allPermutations.end(), ansFromBelow.begin(), ansFromBelow.end());
    }

    return allPermutations;
}

// Function to print all generated permutations
void printAllPermutations(const vector<string>& allPermutations)
{
    for(const auto& permutation: allPermutations)
    {
        for(char ch: permutation)
        {
            cout << ch;
        }
        cout << ", ";
    }
    cout << endl;
}

int main()
{
    string original = "abc";
    string processed = "";

    vector<string> allPermutations;

    // generatingPermutations1(0, original, processed, allPermutations);
    // allPermutations = generatingPermutations2(0, original, processed, allPermutations);
    allPermutations = generatingPermutations3(0, original, processed);

    printAllPermutations(allPermutations);

    return 0;
}
