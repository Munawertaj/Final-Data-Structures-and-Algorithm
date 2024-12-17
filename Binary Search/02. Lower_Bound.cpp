#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {

    int low = 0, high = nums.size() - 1;
    int ans = high + 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else 
            low = mid + 1;
    }
    
    return ans;
}

int main() {

    vector<int> nums = {3, 5, 8, 15, 19};
    int target = 9;
    int index = lowerBound(nums, target);
    cout << "The lower bound is the index: " << index << "\n";
    return 0;
}