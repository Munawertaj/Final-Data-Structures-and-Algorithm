#include<iostream>
#include<vector>
#include<set>

using namespace std;

void generateSubsets(int index, vector<int>& original, vector<int>& subset, set<vector<int>>& allSubSets)
{
    if(index == original.size())
    {
        allSubSets.insert(subset);
        return;
    }

    // Include the current item
    subset.push_back(original[index]);
    generateSubsets(index + 1,  original, subset, allSubSets);
    
    // Exclude the current item
    subset.pop_back();
    generateSubsets(index + 1,  original, subset, allSubSets);

}



// Function to print all generated Subsets
void printAllSubSets(set<vector<int>>& allSubSets)
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
    vector<int> nums = {1, 2, 2};
    vector<int> subset = {};
    set<vector<int>> allSubsets;

    generateSubsets(0, nums, subset, allSubsets);

    printAllSubSets(allSubsets);

}