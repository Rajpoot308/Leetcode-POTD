class Solution {
public:
// 1.
    // int maxAliceScore(vector<int>& piles, int n, int i, int M, bool Alice) {
    //     // base case 
    //     if(i >= n) {
    //         return 0;
    //     }

    //     int stoneSum = 0;
    //     int result = Alice == true ? INT_MIN : INT_MAX;
    //     for(int X = 1; X <= min(2*M, n-i); X++) {
    //         stoneSum += piles[i+X-1];
            
    //         if(Alice) {
    //             result = max(result, stoneSum + maxAliceScore(piles, n, i+X, max(M, X), false));
    //         }
    //         else {
    //             result = min(result, maxAliceScore(piles, n, i+X, max(M, X), true));
    //         }
    //     }

    //     return result;
    // }
    // int stoneGameII(vector<int>& piles) {
    //     int n = piles.size();
    //     int i = 0;
    //     int M = 1;
    //     bool Alice = true;

    //     return maxAliceScore(piles, n, i, M, Alice);
    // }



    int maxAliceScore(vector<int>& piles, int n, int i, int M, int Alice, vector<vector<vector<int>>>& dp) {
        // base case 
        if(i >= n) {
            return 0;
        }

        if(dp[Alice][i][M] != -1) return dp[Alice][i][M];

        int stoneSum = 0;
        int result = Alice == 1 ? INT_MIN : INT_MAX;
        for(int X = 1; X <= min(2*M, n-i); X++) {
            stoneSum += piles[i+X-1];
            
            if(Alice) {
                result = max(result, stoneSum + maxAliceScore(piles, n, i+X, max(M, X), 0, dp));
            }
            else {
                result = min(result, maxAliceScore(piles, n, i+X, max(M, X), 1, dp));
            }
        }

        return dp[Alice][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int i = 0;
        int M = 1;
        int Alice = 1;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));

        return maxAliceScore(piles, n, i, M, Alice, dp);
    }
};