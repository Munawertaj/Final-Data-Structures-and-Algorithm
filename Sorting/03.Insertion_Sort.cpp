#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& nums)
{
    int total = nums.size();

    for(int i = 0; i < total - 1; ++i)
    {
        for(int j = i + 1; j > 0; --j)
        {
            if(nums[j] < nums[j - 1])
                swap(nums[j], nums[j - 1]);
            else
                break;
        }
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
    // vector<int> nums = {8, 7, 4, 6, 5, 1, 3, 2};
    vector<int> nums = {5, 4, 3 ,2, 1};

    insertionSort(nums);

    printArray(nums);

}