class Solution {
public:


// 1. bottom to top recursion 
    
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

// 2. recursion + memoization
    int totalDistinctWays(int currStep, int n, vector<int>& dp) {
        
        if(currStep == n) return 1;
        if(currStep > n) return 0;

        if(dp[currStep] != -1) return dp[currStep];

        int count = 0;
        for(int i = 1; i < 3; i++) {
            int subCount = totalDistinctWays(currStep + i, n, dp); 
            count = count + subCount;
            dp[currStep] = count;
        }

        return dp[currStep];
    }
     
    int climbStairs(int n) {
        int currStep = 0;
        vector<int> dp(n, -1);
        return totalDistinctWays(currStep, n, dp);
    }
};