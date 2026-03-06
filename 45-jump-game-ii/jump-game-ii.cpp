class Solution {
public:

// 1. Recursion T.C. O(n^n) S.C. auxilary space O(n) 

    // int computeMinimumJump(vector<int>& nums, int i, int n) {
    //     if(i == n-1) {
    //         return 0;
    //     }

    //     int minJump = n-1;

    //     for(int j = i + 1; j <= i + nums[i]; j++) {

    //         if(j < n) {
    //             int totalJump = 1 + computeMinimumJump(nums, j, n);
    //             minJump = min(minJump, totalJump);
    //         }
    //     }

    //     return minJump;
    // }
    // int jump(vector<int>& nums) {
    //     int n = nums.size();
    //     int startInd = 0;

    //     return computeMinimumJump(nums, startInd, n);
    // }


// 2. recursion + Memoization dp(iterative way) T.C. O(n^2) S.C. O(n) + O(n)
    // int computeMinimumJump(vector<int>& nums, int i, int n, vector<int>& dp) {
    //     if(i == n-1) {
    //        return 0;
    //     }

    //     if(dp[i] != -1) return dp[i];

    //     int minJump = n-1;

    //     for(int j = i + 1; j <= i + nums[i]; j++) {

    //         if(j < n) {
    //             int totalJump = 1 + computeMinimumJump(nums, j, n, dp);
    //             minJump = min(minJump, totalJump);
    //         }
    //     }

    //     dp[i] = minJump;
    //     return dp[i];
    // }
    // int jump(vector<int>& nums) {
    //     int n = nums.size();
    //     int startInd = 0;
    //     vector<int> dp(n, -1);

    //     return computeMinimumJump(nums, startInd, n, dp);
    // }

// 3. recursion + dp(tabulation) T.C. O(n^2) S.C. O(n) 
    // int jump(vector<int>& nums) {
    //     int n = nums.size();
    //     int startInd = 0;
    //     vector<int> dp(n, n-1);

    //     dp[n-1] = 0;
        
    //     for(int i = n-2; i >= 0; i--) {
    //         int minJump = n-1;

    //         for(int j = i + 1; j <= i + nums[i]; j++) {
    //             if(j < n && (dp[j] != n-1)) {
    //                 int totalJump = 1 + dp[j];
    //                 minJump = min(minJump, totalJump);
    //             }
    //         }

    //        dp[i] = minJump;            
    //     }

    //     return dp[0];
    // }

// 4. Greedy (range based method) T.C. O(n) S.C. O(1)
    int jump(vector<int>& nums) {
        int n = nums.size();

        int jump = 0;
        int l = 0, r = 0, i = 0;
        
        while(i < n-1) {
            int extreme = 0;
            for(int j = l; j <= r; j++) {
                extreme = max(j + nums[j], extreme);
            }
            l = i + 1;
            r = extreme;
            i = r;
            jump++;
        }

        return jump;
    }
};