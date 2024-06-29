#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find all indices of target in arr and store them in allIndex
void findAllIndices1(int index, int target, const vector<int>& arr, vector<int>& allIndices)
{
    if (index == arr.size())
        return;

    if (arr[index] == target) 
        allIndices.push_back(index);

    findAllIndices1(index + 1, target, arr, allIndices);
}

// Recursive function that returns a vector of all indices of target in arr
vector<int> findAllIndices2(int index, int target, const vector<int>& arr, vector<int> allIndices)
{
    if (index == arr.size())
        return allIndices;

    if (arr[index] == target)
        allIndices.push_back(index);

    return findAllIndices2(index + 1, target, arr, allIndices);
}

// Recursive function that returns a vector of all indices of target in arr
vector<int> findAllIndices3(int index, int target, const vector<int>& arr)
{
    if (index == arr.size()) // Base case: if index reaches the end of the array, return an empty vector
        return {};

    vector<int> allIndices;
    if (arr[index] == target) // If the current element matches the target, store the index
        allIndices.push_back(index);

    // Recursive call to get indices from the rest of the array
    vector<int> indicesFromBelowCalls = findAllIndices3(index + 1, target, arr);

    // Insert indices from recursive calls into the current allIndices
    allIndices.insert(allIndices.end(), indicesFromBelowCalls.begin(), indicesFromBelowCalls.end());
    return allIndices;
}

// Function to print the elements of a vector
void printArray(const vector<int>& arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 4, 8, 4, 10, 12}; 
    vector<int> allIndices;

    int target = 4; 

    
    findAllIndices1(0, target, arr, allIndices);
    printArray(allIndices);

    allIndices.clear(); // Clear the vector for the next function
    
    allIndices = findAllIndices2(0, target, arr, allIndices);
    printArray(allIndices);


    allIndices = findAllIndices3(0, target, arr);
    printArray(allIndices);

    return 0;
}
