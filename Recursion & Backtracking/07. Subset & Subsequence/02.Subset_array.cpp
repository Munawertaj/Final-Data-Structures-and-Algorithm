#include<iostream>
#include<vector>

using namespace std;

// Function to generate all Subsets(Not pass by references) and store them in allSubsets
void generateSubsets1(int index, vector<int>& original, vector<int>& subset, vector<vector<int>>& allSubSets)
{
    if(index == original.size())
    {
        allSubSets.push_back(subset);
        return;
    }
    // Exclude the current item
    generateSubsets1(index + 1,  original, subset, allSubSets);

    // Include the current item
    subset.push_back(original[index]);
    generateSubsets1(index + 1,  original, subset, allSubSets);

    // Remove the item which is added
    subset.pop_back();
}

// Function to generate all Subsets and store them in allSubsets(MOSTLY USED)
void generateSubsets2(int index, vector<int>& original, vector<int>& subset, vector<vector<int>>& allSubSets)
{
    if(index == original.size())
    {
        allSubSets.push_back(subset);
        return;
    }

    // Include the current item
    subset.push_back(original[index]);
    generateSubsets2(index + 1,  original, subset, allSubSets);
    
    // Exclude the current item
    subset.pop_back();
    generateSubsets2(index + 1,  original, subset, allSubSets);

}

// Function to generate all Subsets and return them
vector<vector<int>> generateSubsets3(int index, vector<int>& original, vector<int>& subset, vector<vector<int>>& allSubSets)
{
    if(index == original.size())
    {
        allSubSets.push_back(subset);
        return allSubSets;
    }

    // Include the current item
    subset.push_back(original[index]);
    allSubSets = generateSubsets3(index + 1,  original, subset, allSubSets);
    
    // Exclude the current item
    subset.pop_back();
    allSubSets = generateSubsets3(index + 1,  original, subset, allSubSets);

    return allSubSets;
}

// Function to generate all Subsets and return them, using concatenation
vector<vector<int>> generateSubsets4(int index, vector<int>& original, vector<int>& subset)
{
    if(index == original.size())
    {
        return {subset};
    }

    // Include the current item
    subset.push_back(original[index]);
    vector<vector<int>> allSubSetsFromLeft = generateSubsets4(index + 1,  original, subset);
    
    // Exclude the current item
    subset.pop_back();
    vector<vector<int>> allSubSetsFromRight = generateSubsets4(index + 1,  original, subset);

    // Combine results from both recursions
    allSubSetsFromLeft.insert(allSubSetsFromLeft.end(), allSubSetsFromRight.begin(), allSubSetsFromRight.end());

    return allSubSetsFromLeft;
}

// Function to print all generated Subsets
void printAllSubSets(vector<vector<int>>& allSubSets)
{
    for(auto& SubSet: allSubSets)
    {
        cout << "[ ";
        for(int val: SubSet)
        {
            cout << val << ", ";
        }
        cout << "]\n";
    }
    cout << endl;
}



int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> subset = {};
    vector<vector<int>> allSubsets;

    // generateSubsets1(0, nums, subset, allSubsets);
    generateSubsets2(0, nums, subset, allSubsets);
    // allSubsets = generateSubsets3(0, nums, subset, allSubsets);
    // allSubsets = generateSubsets4(0, nums, subset);

    printAllSubSets(allSubsets);
    return 0;
}