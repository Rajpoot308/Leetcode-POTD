class Solution {
public:

// 1. Recursion + Greedy 
    
    // bool canReachAtLast(vector<int>& nums, int i, int n) {
    //     if(i == n) return true;
    //     if(i > n) return false;

    //     for(int j = nums[i]; j > 0; j--) {
    //         if(canReachAtLast(nums, i + j, n)) return true;
    //     }

    //     return false;
    // }

    // bool canJump(vector<int>& nums) {
    //     int start = 0;
    //     int last = nums.size()-1;

    //     return canReachAtLast(nums, start, last);
    // }

// 2. Recursion + Memoization (iterative way) 
    bool canReachAtLast(vector<int>& nums, int i, int n, vector<int>& dp) {
        if(i == n) return true;
        
        if(dp[i] != -1) {
            return dp[i];
        }

        for(int j = nums[i]; j > 0; j--) {
        
            if(i + j <= n) {
                dp[i+j] = canReachAtLast(nums, i+j, n, dp);
                if(dp[i+j] == 1) return dp[i+j];
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        int start = 0;
        int last = nums.size()-1;
        vector<int> dp(last + 1, -1);

        return canReachAtLast(nums, start, last, dp);
    }
};