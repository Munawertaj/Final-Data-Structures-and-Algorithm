#include<iostream>
#include<vector>
using namespace std;

// Traversing from left to right
int longestIncreasingSubSequence(int index, vector<int>& nums, vector<int>& dp) {
    
    if(dp[index] != -1)
        return dp[index];
    
    int ans = 1;

    for(int i = 0; i < index; ++i) {
        if(nums[i] < nums[index])
            ans = max(ans , longestIncreasingSubSequence(i, nums, dp) + 1);
    }

    return dp[index] = ans;
}

// Traversing from right to left
int longestIncreasingSubSequence2(int index, vector<int>& nums, vector<int>& dp) {
    if(index < 0)
        return 0;
    
    int ans = 1;
    if(dp[index] != -1)
        return dp[index];
    for(int i = index - 1; i >= 0; --i) {
        if(nums[i] < nums[index])
            ans = max(ans , longestIncreasingSubSequence2(i, nums, dp) + 1);
    }

    return dp[index] = ans;
}


int main() {
    vector<int> nums = {2, 6, 3, 5, 4, 7, 20, 18};
    int len = nums.size();
    int ans = 0;
    vector<int> dp(len, -1);

    // For traversing left to right
    for(int i = 0; i < len; i++) {
        ans = max(ans, longestIncreasingSubSequence(i, nums, dp));
    }

    // // For Traversing right to left
    // for(int i = len - 1; i >= 0; i--) {
    //     ans = max(ans, longestIncreasingSubSequence2(i, nums, dp));
    // }

    cout << ans;
}