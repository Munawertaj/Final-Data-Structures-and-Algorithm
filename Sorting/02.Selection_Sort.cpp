#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findMinimumIndex(vector<int>& nums, int start)
{
    int minimum = INT_MAX, index;

    for(int i = start; i < nums.size(); ++i)
    {
        if(nums[i] < minimum)
        {
            minimum = nums[i];
            index = i;
        }
    }
    return index;
}

void selectionSort(vector<int>& nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        int index = findMinimumIndex(nums, i);
        
        if(nums[i] != nums[index])
            swap(nums[i], nums[index]);
    }
}


void printArray(vector<int>& nums)
{
    for (int val : nums)
    {
        cout << val << " ";
    }
    cout << endl;
}


int main()
{
    vector<int> nums = {8, 7, 4, 6, 5, 1, 3, 2};
    // vector<int> nums = {5, 4, 3 ,2, 1};

    selectionSort(nums);

    printArray(nums);

}