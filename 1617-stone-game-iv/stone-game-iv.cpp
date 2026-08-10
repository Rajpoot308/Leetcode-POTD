class Solution {
public:
// 1. recursion
    // bool winnerSquareGame(int n) {
        
    //     if(n == 0) return false;

    //     for(int i = 1; i*i <= n; i++) {
             
    //          if(!winnerSquareGame(n - i*i)) {
    //             return true;
    //          }
    //     }

    //     return false;
    // }

// 2. recursion + memoization (top down approch)
    bool isAliceWinner(int n, vector<int>& memo) {
        
        if(n == 0) return false;

        if(memo[n] != -1) return memo[n];

        for(int i = 1; i*i <= n; i++) {
             
             if(!isAliceWinner(n - i*i, memo)) {
                return memo[n] = true;
             }
        }

        return memo[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> memo(n+1, -1);

        return isAliceWinner(n, memo);
    }
};