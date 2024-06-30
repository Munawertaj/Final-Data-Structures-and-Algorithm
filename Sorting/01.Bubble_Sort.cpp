#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& nums)
{
    int total = nums.size();

    for(int i = total; i >= 0; --i)
    {
        for(int j = 1; j < total; ++j)
        {
            if(nums[j - 1] > nums[j])
                swap(nums[j - 1], nums[j]);
        }
    }
}

void bubbleSortEfficient(vector<int>& nums)
{
    int total = nums.size();

    for(int i = total; i >= 0; --i)
    {
        bool isSwapped = true;
        for(int j = 1; j < total; ++j)
        {
            if(nums[j - 1] > nums[j])
            {
                swap(nums[j - 1], nums[j]);
                isSwapped = false;
            }
        }
        if(isSwapped)
            return;
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

    // bubbleSort(nums);
    bubbleSortEfficient(nums);

    printArray(nums);

}