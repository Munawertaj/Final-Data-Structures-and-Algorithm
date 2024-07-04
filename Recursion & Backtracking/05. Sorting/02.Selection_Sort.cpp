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

void selectionSort(vector<int>& nums, int index)
{
    if(index == nums.size())
        return;

    int minValueIndex = findMinimumIndex(nums, index);
    
    if(nums[index] != nums[minValueIndex])
        swap(nums[index], nums[minValueIndex]);
    
    selectionSort(nums, index + 1);
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
    
    selectionSort(nums, 0);

    printArray(nums);

}