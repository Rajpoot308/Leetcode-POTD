class Solution {
public:

// 1. recursion T.C -   S.C. - 
    
    // int countUniquePath(int m, int n, vector<vector<int>>& obstacleGrid) {
        
       

    //     if(m == 0 && n == 0 && (obstacleGrid[m][n] != 1)) return 1;
        
    //     if(m < 0 || n < 0 || (obstacleGrid[m][n] == 1)) return 0;

    //     int countPaths = countUniquePath(m-1, n, obstacleGrid) + countUniquePath(m, n-1, obstacleGrid);

    //     return countPaths;
    // }

    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();

    //     return countUniquePath(m-1, n-1, obstacleGrid);
    // }

// 2. recursion + memoization
    
    // int countUniquePath(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& countPathDp) {

    //     if(m == 0 && n == 0 && (obstacleGrid[m][n] != 1)) return 1;
    //     if(m < 0 || n < 0 || (obstacleGrid[m][n] == 1)) return 0;

    //     if(countPathDp[m][n] != 0) return countPathDp[m][n];

    //     countPathDp[m][n] = countUniquePath(m-1, n, obstacleGrid, countPathDp) + countUniquePath(m, n-1, obstacleGrid, countPathDp);

    //     return countPathDp[m][n];
    // }

    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();

    //     vector<vector<int>> countPathDp(m, vector<int> (n, 0));
    //     return countUniquePath(m-1, n-1, obstacleGrid, countPathDp);
    // }

// 3. tabulation (iterative way)
    
    // int countUniquePath(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& countPathDp) {

    //     if(obstacleGrid[m][n] == 1) return 0;

    //     // countPathDp[0][0] = 1;

    //     // for(int i = 0; i <= m; i++) {
    //     //     for(int j = 0; j <= n; j++) {

    //     //         if(obstacleGrid[i][j] != 1) {

    //     //             if(i > 0 && j > 0 && (obstacleGrid[i-1][j] != 1) &&)
    //     //         }
    //     //     }
    //     // }

    //     for(int i = 0; i <= m; i++) {
    //         if(obstacleGrid[i][0] == 1) {
    //             break;
    //         }
    //         countPathDp[i][0] = 1;
    //     }

    //     for(int j = 0; j <= n; j++) {
    //         if(obstacleGrid[0][j] == 1) {
    //             break;
    //         }
    //         countPathDp[0][j] = 1;
    //     }

    //     for(int i = 1; i <= m; i++) {
    //         for(int j = 1; j <= n; j++) {

    //             if(obstacleGrid[i][j] != 1) {
    //                 countPathDp[i][j] = countPathDp[i-1][j] + countPathDp[i][j-1];
    //             }

    //         }
    //     }

    //     return countPathDp[m][n];
    // }

    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();

    //     vector<vector<int>> countPathDp(m, vector<int> (n, 0));
    //     return countUniquePath(m-1, n-1, obstacleGrid, countPathDp);
    // }

// 4. space optimaization
    
    int countUniquePath(int m, int n, vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid[m][n] == 1 || obstacleGrid[0][0] == 1) return 0;

        vector<int> prev(n+1, 0);

        for(int i = 0; i <= m; i++) {
            vector<int> curr(n+1, 0);
            for(int j = 0; j <= n; j++) {

                if(obstacleGrid[i][j] != 1) {
                    
                    if(i == 0 && j == 0) {
                        curr[j] = 1;
                    }
                    else {
                        int left = j > 0 ? curr[j-1] : 0;
                        int up = prev[j];
                        curr[j] = left + up;
                    }
                }
            }
            prev = curr;
        }

        return prev[n];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return countUniquePath(m-1, n-1, obstacleGrid);
    }
    
};