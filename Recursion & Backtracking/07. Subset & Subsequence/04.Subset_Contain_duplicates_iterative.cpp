#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> generateSubsetsWithoutDuplicate(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> allSubsets;
    allSubsets.push_back({}); // Add an empty subset
    
    int start = 0, end = 0;

    for(int i = 0; i < nums.size(); ++i)
    {
        start = 0;
        // if current and previous element is same, s = e + 1
        if (i > 0 && nums[i] == nums[i - 1])
            start = end + 1;
        
        end = allSubsets.size() - 1;

        for(int j = start; j <= end; j++)
        {
            vector<int> subset = allSubsets[j];
            subset.push_back(nums[i]);
            allSubsets.push_back(subset);
        }
    }

    return allSubsets;
}

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
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> allSubsets = generateSubsetsWithoutDuplicate(nums);

    printAllSubSets(allSubsets);

}