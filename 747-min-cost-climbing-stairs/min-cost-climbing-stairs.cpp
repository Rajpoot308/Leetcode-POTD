class Solution {
public:
// 1. top to bottom approch T.C.-O(2^n) S.C.-O(n)

    // int miniCostClimbingStairs(vector<int>& cost, int n){
    //     // 1. base case
    //     if(n == 1 || n == 0) {
    //         return 0;
    //     }

    //     int l = miniCostClimbingStairs(cost, n-1)+cost[n-1];
    //     int r = miniCostClimbingStairs(cost, n-2)+cost[n-2];

    //     return min(l, r);


    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     return miniCostClimbingStairs(cost, n);
    // }


// 2. recursion + memoization T.C.-O(n) S.C.-O(n)+O(n)
    // int miniCostClimbingStairs(vector<int>& cost, int n, vector<int>& dp){
    //     // 1. base case
    //     if(n == 1 || n == 0) {
    //         return 0;
    //     }

    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     int l = miniCostClimbingStairs(cost, n-1, dp)+cost[n-1];
    //     int r = miniCostClimbingStairs(cost, n-2, dp)+cost[n-2];

    //     dp[n] = min(l, r);

    //     return dp[n];


    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n+1, -1);
    //     return miniCostClimbingStairs(cost, n, dp);
    // }


// 3. tabulation(iterative way) Bottum up approch T.C.-O(n) S.C.-O(n)(not recursive stack)

    // int miniCostClimbingStairs(vector<int>& cost, int n, vector<int>& dp){
    //     // 1. base case
    //     dp[0] = 0;
    //     dp[1] = 0;

    //     for(int i = 2; i <= n; i++){
    //         int l = dp[i-1]+cost[i-1];
    //         int r = dp[i-2]+cost[i-2];
    //         dp[i] = min(l, r);
    //     }

    //     return dp[n];


    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n+1, -1);
    //     return miniCostClimbingStairs(cost, n, dp);
    // }

// 4. space optimization T.C.-O(n) S.C.-O(1)

    // int miniCostClimbingStairs(vector<int>& cost, int n){
    //     // 1. base case
    //     int prev2= 0;
    //     int prev1= 0;
    //     if(n == 1) return prev1;
    //     if(n == 0) return prev2;
    //     int curr = 0;
    //     for(int i = 2; i <= n; i++){
    //         int l = prev1+cost[i-1];
    //         int r = prev2+cost[i-2];
    //         curr = min(l,r);
    //         prev2 = prev1;
    //         prev1 = curr;
    //     }

    //     return curr;
    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     return miniCostClimbingStairs(cost, n);
    // }
    
// 1.1 Fix the bug in approch 1
    // int minCostClimbStairs(vector<int>& cost, int n) {
        
    //     if(n <= 0) return 0;

    //     int l = minCostClimbStairs(cost, n-1) + cost[n-1];
    //     int m = n > 1 ? minCostClimbStairs(cost, n-2) + cost[n-2] : minCostClimbStairs(cost, n-2);

    //     return min(l, m);
    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();

    //     return minCostClimbStairs(cost, n);
    // }

// 1.2 Fix the bug in approch 2

    // int costToClimbing(vector<int>& cost, int n, vector<int>& lookUpDp) {
    //     if(n <= 0) {
    //         return 0;
    //     }
        
    //     if(lookUpDp[n] != -1) {
    //         return lookUpDp[n];
    //     }

    //     int first = cost[n-1] + costToClimbing(cost, n-1, lookUpDp);
    //     int second = n > 1 ? cost[n-2] + costToClimbing(cost, n-2, lookUpDp) : costToClimbing(cost, n-2, lookUpDp);

    //     lookUpDp[n] = min(first, second);
    //     return lookUpDp[n];
    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> lookUpDp(n+1, -1);
    //     return costToClimbing(cost, n, lookUpDp);
    // }

// 1.3 Better way to do approch 3
    // int costToClimbing(vector<int>& cost, int n, vector<int>& minCostDp) {
    //     if(n <= 0) return 0;
        
    //     minCostDp[0] = 0;
    //     minCostDp[1] = 0;

    //     for(int i = 2; i <= n; i++) {
            
    //         minCostDp[i] = min(minCostDp[i-1] + cost[i-1], minCostDp[i-2] + cost[i-2]);
    //     }

    //     return minCostDp[n];
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> minCostDp(n+1, -1);
    //     return costToClimbing(cost, n, minCostDp);
    // }

// 1.4 Better way to do approch 4
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        if(n <= 0) return 0;

        int prev = 0;
        int pprev = 0;
        int curr = 0;

        for(int i = 2; i <= n; i++) {
            curr = min(prev + cost[i-1], pprev + cost[i-2]);
            pprev = prev;
            prev = curr;
        }

        return curr;
    }
};