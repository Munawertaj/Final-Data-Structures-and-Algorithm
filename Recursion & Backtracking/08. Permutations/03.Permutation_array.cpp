#include <iostream>
#include <vector>
using namespace std;

// Function to generate all permutations of the original vector
void generatingPermutations1(int index, vector<int>& original, vector<int> processed, vector<vector<int>>& allPermutations)
{
    if(index == original.size())
    {
        allPermutations.push_back(processed);
        return;
    }

    int num = original[index];
    int length = processed.size();

    // Insert the current number at each position in the processed vector
    for(int i = 0; i <= length; ++i)
    {
        vector<int> temp = processed; // Create a copy of the processed vector
        temp.insert(temp.begin() + i, num); // Insert the number at position i

        // Recurse with the new processed vector including the current number
        generatingPermutations1(index + 1, original, temp, allPermutations);
    }
}

// Similar to generatingPermutations1 but returns the result vector
vector<vector<int>> generatingPermutations2(int index, vector<int>& original, vector<int> processed, vector<vector<int>>& allPermutations)
{
    if(index == original.size())
    {
        allPermutations.push_back(processed);
        return allPermutations;
    }

    int num = original[index];
    int length = processed.size();

    // Insert the current number at each position in the processed vector
    for(int i = 0; i <= length; ++i)
    {
        vector<int> temp = processed; // Create a copy of the processed vector
        temp.insert(temp.begin() + i, num); // Insert the number at position i

        // Recursively generate permutations with the new processed vector including the current number
        allPermutations = generatingPermutations2(index + 1, original, temp, allPermutations);
    }

    return allPermutations; // Return the accumulated permutations
}

// Function to generate permutations and return the result directly
vector<vector<int>> generatingPermutations3(int index, vector<int>& original, vector<int> processed)
{
    if(index == original.size())
    {
        return {processed};
    }

    int num = original[index];
    int length = processed.size();

    vector<vector<int>> allPermutations;

    // Insert the current number at each position in the processed vector
    for(int i = 0; i <= length; ++i)
    {
        vector<int> temp = processed; // Create a copy of the processed vector
        temp.insert(temp.begin() + i, num); // Insert the number at position i

        // Get permutations from the recursive call
        vector<vector<int>> ansFromBelow = generatingPermutations3(index + 1, original, temp);

        // Add the new permutations to the result vector
        allPermutations.insert(allPermutations.end(), ansFromBelow.begin(), ansFromBelow.end());
    }

    return allPermutations;
}

// Function to print all generated permutations
void printAllPermutations(const vector<vector<int>>& allPermutations)
{
    for(const auto& permutation: allPermutations)
    {
        cout << "[";
        for(int num: permutation)
        {
            cout << num << ", ";
        }
        cout << "]\n";
    }
    cout << endl;
}

int main()
{
    vector<int> original = {1, 2, 3};
    vector<int> processed;

    vector<vector<int>> allPermutations;

    // generatingPermutations1(0, original, processed, allPermutations);
    // allPermutations = generatingPermutations2(0, original, processed, allPermutations);
    allPermutations = generatingPermutations3(0, original, processed);

    printAllPermutations(allPermutations);

    return 0;
}
