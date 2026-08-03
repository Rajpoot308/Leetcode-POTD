class Solution {
public:
// 1. recursive 1 T.C. O(3^n) S.C. O(1) + recursive stack O(n)
    // int scoreOfAlice(vector<int>& stoneValue, int i, int j) {
    //     if(i > j) return 0;
    //     if(i == j) return stoneValue[i];

    //     int first = stoneValue[i] + min(scoreOfAlice(stoneValue, i+2, j), min(scoreOfAlice(stoneValue, i+3, j), scoreOfAlice(stoneValue, i+4, j)));

    //     int second = stoneValue[i] + stoneValue[i+1] + min(scoreOfAlice(stoneValue, i+3, j), min(scoreOfAlice(stoneValue, i+4, j), scoreOfAlice(stoneValue, i+5, j)));
        
    //     int third = -1000;
    //     if(i+2 <= j) {
    //         third = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] + min(scoreOfAlice(stoneValue, i+4, j), min(scoreOfAlice(stoneValue, i+5, j), scoreOfAlice(stoneValue, i+6, j)));
    //     }

    //     return max(first, max(second, third));
    // }
    // string stoneGameIII(vector<int>& stoneValue) {
    //     int n  = stoneValue.size();
    //     int totalScore = accumulate(stoneValue.begin(), stoneValue.end(), 0);

    //     int AliceScore = scoreOfAlice(stoneValue, 0, n-1);
    //     int BobScore = totalScore - AliceScore;

    //     cout << totalScore <<" "<< AliceScore <<" "<< BobScore <<endl;

    //     if(AliceScore > BobScore) return "Alice";
    //     if(AliceScore == BobScore) return "Tie";
    //     return "Bob";
    // }

// 1.2 Top down approch (recursion + memoization) 
    // int scoreOfAlice(vector<int>& stoneValue, int i, int j, vector<vector<int>>& dp) {
    //     if(i > j) return 0;
    //     if(i == j) return stoneValue[i];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int first = stoneValue[i] + min(scoreOfAlice(stoneValue, i+2, j, dp), min(scoreOfAlice(stoneValue, i+3, j, dp), scoreOfAlice(stoneValue, i+4, j, dp)));

    //     int second = stoneValue[i] + stoneValue[i+1] + min(scoreOfAlice(stoneValue, i+3, j, dp), min(scoreOfAlice(stoneValue, i+4, j, dp), scoreOfAlice(stoneValue, i+5, j, dp)));
        
    //     int third = -1000;
    //     if(i+2 <= j) {
    //         third = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] + min(scoreOfAlice(stoneValue, i+4, j, dp), min(scoreOfAlice(stoneValue, i+5, j, dp), scoreOfAlice(stoneValue, i+6, j, dp)));
    //     }

    //     return dp[i][j] = max(first, max(second, third));
    // }
    // string stoneGameIII(vector<int>& stoneValue) {
    //     int n  = stoneValue.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));

    //     int totalScore = accumulate(stoneValue.begin(), stoneValue.end(), 0);

    //     int AliceScore = scoreOfAlice(stoneValue, 0, n-1, dp);
    //     int BobScore = totalScore - AliceScore;

    //     cout << totalScore <<" "<< AliceScore <<" "<< BobScore <<endl;

    //     if(AliceScore > BobScore) return "Alice";
    //     if(AliceScore == BobScore) return "Tie";
    //     return "Bob";
    // }

// 2.1 recursion 2 
    // int maxiScoreDiff(vector<int>& stoneValue, int i, int j) {
    //     if(i > j) return 0;
    //     if(i == j) return stoneValue[i];

    //     int first = stoneValue[i] - maxiScoreDiff(stoneValue, i+1, j);
    //     int second = stoneValue[i] + stoneValue[i+1] - maxiScoreDiff(stoneValue, i+2, j);
        
    //     int third = -1000;
    //     if(i+2 <= j) {
    //         third = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - maxiScoreDiff(stoneValue, i+3, j);
    //     }

    //     return max(first, max(second, third));
    // }
    // string stoneGameIII(vector<int>& stoneValue) {
    //     int n  = stoneValue.size();

    //     int scoreDiff= maxiScoreDiff(stoneValue, 0, n-1);
        

    //     if(scoreDiff > 0) return "Alice";
    //     if(scoreDiff == 0) return "Tie";
    //     return "Bob";
    // }

// 2.2 recursion + memoization (Top down approch)
    int maxiScoreDiff(vector<int>& stoneValue, int i, int j, vector<int>& dp) {
        if(i > j) return 0;
        if(i == j) return stoneValue[i];

        if(dp[i] != -1) return dp[i];

        int first = stoneValue[i] - maxiScoreDiff(stoneValue, i+1, j, dp);
        int second = stoneValue[i] + stoneValue[i+1] - maxiScoreDiff(stoneValue, i+2, j, dp);
        
        int third = -1000;
        if(i+2 <= j) {
            third = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - maxiScoreDiff(stoneValue, i+3, j, dp);
        }

        return dp[i] = max(first, max(second, third));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n  = stoneValue.size();
        vector<int> dp(n, -1);

        int scoreDiff= maxiScoreDiff(stoneValue, 0, n-1, dp);
        

        if(scoreDiff > 0) return "Alice";
        if(scoreDiff == 0) return "Tie";
        return "Bob";
    }

// 2.3 Bottom up approch (tabulation) T.C. O(n2) S.C. O(n2) 

    // string stoneGameIII(vector<int>& stoneValue) {
    //     int n  = stoneValue.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));

    //     for(int gap = 0; gap < n; gap++) {
    //         for(int i = 0; i < n - gap; i++) {
    //             int j = gap + i;

    //             if(i == j) {
    //                 dp[i][j] = stoneValue[i];
    //             }
    //             else {
    //                 int a = i + 1 <= j ? dp[i+1][j] : 0;
    //                 int b = i + 2 <= j ? dp[i+2][j] : 0;
    //                 int c = i + 3 <= j ? dp[i+3][j] : 0;

    //                 int third = -1000;
    //                 if(i+2 <= j) {
    //                     third = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - c;
    //                 }
    //                 dp[i][j] = max(stoneValue[i] - a, max(stoneValue[i] + stoneValue[i+1] - b,  third));
    //             }
    //         }
    //     }

    //     int scoreDiff = dp[0][n-1];

    //     if(scoreDiff > 0) return "Alice";
    //     if(scoreDiff == 0) return "Tie";
    //     return "Bob";
    // }

};