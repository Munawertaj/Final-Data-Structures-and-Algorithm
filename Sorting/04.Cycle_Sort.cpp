#include<iostream>
#include<vector>
using namespace std;

// For numbers between 1 to N
void cycleSort(vector<int>& nums)
{
    int total = nums.size();
    int index = 0;

    while(index < total)
    {
        int correctIndex = nums[index];     // For numbers between 0 to N-1
        // int correctIndex = nums[index] - 1;     // For numbers between 1 to N

        if(nums[index] != nums[correctIndex])
            swap(nums[index], nums[correctIndex]);
        else
            index++;
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
    vector<int> nums = {4, 3 ,2, 1, 0};

    cycleSort(nums);

    printArray(nums);

}