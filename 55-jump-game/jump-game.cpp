class Solution {
public:

// 1. Recursion
    
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
    // bool canReachAtLast(vector<int>& nums, int i, int n, vector<int>& dp) {
    //     if(i == n) return true;
        
    //     if(dp[i] != -1) {
    //         return dp[i];
    //     }

    //     for(int j = nums[i]; j > 0; j--) {
        
    //         if(i + j <= n) {
    //             dp[i+j] = canReachAtLast(nums, i+j, n, dp);
    //             if(dp[i+j] == 1) return dp[i+j];
    //         }
    //     }

    //     return false;
    // }

    // bool canJump(vector<int>& nums) {
    //     int start = 0;
    //     int last = nums.size()-1;
    //     vector<int> dp(last + 1, -1);

    //     return canReachAtLast(nums, start, last, dp);
    // }

// 3. recursion + tabulation(dp) 

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 1;

        for(int i = n-2; i >= 0; i--) {

            bool flag = true;
            for(int j = nums[i]; j > 0; j--) {
                if(i+j < n && dp[i+j]) {
                    dp[i] = 1;
                    flag = false;
                    break;
                }
            }

            if(flag) dp[i] = 0;
        }

        return dp[0];
    } 



// 4. 
    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     int last = n-1;

    //     for(int i = n-2; i >= 0; i--) {
    //         if(last-i <= nums[i]) last = i;
    //     }

    //     if(last == 0) return true;
    //     return false;
    // }

// 4. Greedy - Greedy to jump maximum T.C. O(n) S.C. O(1) 
    /* One catch in this problem is that if there is no 0 present in the array then 
       it will be always possible to reach at the end */

    // bool canJump(vector<int>& nums) {
    //     int maxJump = 0;

    //     for(int i = 0; i < nums.size(); i++) {
    //         if(i > maxJump) return false;

    //         maxJump = max(maxJump, i + nums[i]);
    //     }

    //     return true;
    // }
};