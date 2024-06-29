#include<iostream>
#include<vector>
using namespace std;

int rotatedBinarySearch(vector<int>& nums, int target, int left, int right) {
    
    if(left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if(nums[mid] == target)
        return mid;
    
    if (nums[left] <= nums[mid]) {

        if (target >= nums[left] && target <= nums[mid])
            return rotatedBinarySearch(nums, target, left, mid - 1);
        else
            return rotatedBinarySearch(nums, target, mid + 1, right);
    
    }

    if (target >= nums[mid] && target <= nums[right])
        return rotatedBinarySearch(nums, target, mid + 1, right);
    

    return rotatedBinarySearch(nums, target, left, mid - 1);

}

int main() {

    vector<int> nums = {5, 6, 7, 8, 9, 1, 2, 3};
    
    for(int target : nums) {
        cout << rotatedBinarySearch(nums, target, 0, nums.size() - 1) << endl;
    }
    
    cout << rotatedBinarySearch(nums, 10, 0, nums.size() - 1) << endl;

    return 0;
}