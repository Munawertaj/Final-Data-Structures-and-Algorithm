#include<iostream>
#include<vector>
using namespace std;

int maximumIndex(vector<int>& nums, int start, int end)
{
    int maximum = INT_MIN, index;

    for(int i = start; i <= end; ++i)
    {
        if(nums[i] > maximum)
        {
            maximum = nums[i];
            index = i;
        }
    }
    return index;
}

void selectionSort(vector<int>& nums)
{
    int total = nums.size();

    for(int i = total - 1; i >= 0; --i)
    {
        int index = maximumIndex(nums, 0, i);
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