#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target, int left, int right) {
    
    if(left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if(nums[mid] == target)
        return mid;

    else if(nums[mid] > target)
        return binarySearch(nums, target, left, mid - 1);

    else
        return binarySearch(nums, target, mid + 1, right);

}

int main() {

    vector<int> nums = {1, 2, 3, 4, 55, 66, 78};
    int target1 = 1;
    int target2 = 55;
    int target3 = 78;
    int target4 = 5;

    cout << binarySearch(nums, target1, 0, nums.size() - 1) << endl;
    cout << binarySearch(nums, target2, 0, nums.size() - 1) << endl;
    cout << binarySearch(nums, target3, 0, nums.size() - 1) << endl;
    cout << binarySearch(nums, target4, 0, nums.size() - 1) << endl;

    return 0;
}