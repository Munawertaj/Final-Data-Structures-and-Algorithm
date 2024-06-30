#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(int length, int index, vector<int>& nums)
{
    if(length == 0)
        return;
    
    if(index < length)
    {
        if(nums[index] < nums[index - 1])
            swap(nums[index], nums[index - 1]);

        bubbleSort(length, index + 1, nums);
    }
    else
        bubbleSort(length - 1, 1, nums);
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

    int total = nums.size();

    bubbleSort(total, 1, nums);
    printArray(nums);

}