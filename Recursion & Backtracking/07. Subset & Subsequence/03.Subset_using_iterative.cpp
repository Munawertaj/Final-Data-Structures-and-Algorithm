#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generateSubsets(vector<int>& nums)
{
    vector<vector<int>> allSubsets ;
    allSubsets.push_back({});

    for(int val : nums)
    {
        vector<vector<int>> temp;
        for(auto subset : allSubsets)
        {
            temp.push_back(subset);
            subset.push_back(val);
            temp.push_back(subset);
        }
        allSubsets = temp;
    }
    
    return allSubsets;
}

vector<vector<int>> generateSubsets2(vector<int>& arr)
{
    vector<vector<int>> allSubsets;
    allSubsets.push_back(vector<int>()); // Add an empty subset

    for (int num : arr)
    {
        int total = allSubsets.size();

        for (int i = 0; i < total; i++)
        {
            vector<int> subset = allSubsets[i]; // Copy existing subset
            subset.push_back(num); // Add current number
            allSubsets.push_back(subset); // Add the new subset to the outer vector
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
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> allSubsets = generateSubsets(nums);
    // vector<vector<int>> allSubsets = generateSubsets2(nums);

    printAllSubSets(allSubsets);

}