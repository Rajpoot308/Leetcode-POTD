class Solution {
public:


// 1. bottom to top recursion T.C. O(2^n) S.C. O(n) auxilary space
    
    // int totalDistinctWays(int currStep, int n) {
        
    //     if(currStep == n) return 1;
    //     if(currStep > n) return 0;

    //     int count = 0;
    //     for(int i = 1; i < 3; i++) {
    //         int subCount = totalDistinctWays(currStep + i, n); 
    //         count = count + subCount;
    //     }

    //     return count;
    // }
     
    // int climbStairs(int n) {
    //     int currStep = 0;

    //     return totalDistinctWays(currStep, n);
    // }

// 2. recursion + memoization  T.C. O(n) S.C. O(n) + O(n) recursive stack
    // int totalDistinctWays(int currStep, int n, vector<int>& dp) {
        
    //     if(currStep == n) return 1;
    //     if(currStep > n) return 0;

    //     if(dp[currStep] != -1) return dp[currStep];

    //     int count = 0;
    //     for(int i = 1; i < 3; i++) {
    //         int subCount = totalDistinctWays(currStep + i, n, dp); 
    //         count = count + subCount;
    //         dp[currStep] = count;
    //     }

    //     return dp[currStep];
    // }
     
    // int climbStairs(int n) {
    //     int currStep = 0;
    //     vector<int> dp(n, -1);
    //     return totalDistinctWays(currStep, n, dp);
    // }

// 3. iterative way T.C. O(n) S.C. O(n) and no recursive stack
    int totalDistinctWays(int n, vector<int>& dp) {
        
        if(n > 0) dp[1] = 1;
        if(n > 1) dp[2] = 2;

        
        for(int currStep = 3; currStep <= n; currStep++) {
            int count = 0;
            for(int i = 1; i < 3; i++) {
                int subCount = dp[currStep - i]; 
                count = count + subCount;  
            }
            dp[currStep] = count;
        }
        

        return dp[n];
    }
     
    int climbStairs(int n) {

        vector<int> dp(n + 1, 0);
        return totalDistinctWays(n, dp);
    }
};