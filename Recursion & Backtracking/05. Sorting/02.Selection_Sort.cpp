#include<iostream>
#include<vector>
using namespace std;

int findMaximumIndex(vector<int>& nums, int end)
{
    int maximum = INT_MIN, index;

    for(int i = 0; i <= end; ++i)
    {
        if(nums[i] > maximum)
        {
            maximum = nums[i];
            index = i;
        }
    }
    return index;
}

void selectionSort(vector<int>& nums, int index)
{
    if(index == 0)
        return;

    int maxValueIndex = findMaximumIndex(nums, index);
    
    if(nums[index] != nums[maxValueIndex])
        swap(nums[index], nums[maxValueIndex]);
    
    selectionSort(nums, index - 1);
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
    
    int endIndex = nums.size() - 1;
    selectionSort(nums, endIndex);

    printArray(nums);

}