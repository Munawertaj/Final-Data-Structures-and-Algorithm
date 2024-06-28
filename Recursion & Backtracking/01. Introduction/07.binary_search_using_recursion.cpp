#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target, int left, int right) {
    
    if(left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if(nums[mid] == target)
        return mid;

    else if(nums[mid] > target)
        return search(nums, target, left, mid - 1);

    else
        return search(nums, target, mid + 1, right);

}

int main() {

    vector<int> nums = {1, 2, 3, 4, 55, 66, 78};
    int target = 5;

    cout << search(nums, target, 0, nums.size() - 1);
    return 0;
}