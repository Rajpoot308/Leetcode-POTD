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
    
    int countUniquePath(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& countPathDp) {

        if(m == 0 && n == 0 && (obstacleGrid[m][n] != 1)) return 1;
        if(m < 0 || n < 0 || (obstacleGrid[m][n] == 1)) return 0;

        if(countPathDp[m][n] != 0) return countPathDp[m][n];

        countPathDp[m][n] = countUniquePath(m-1, n, obstacleGrid, countPathDp) + countUniquePath(m, n-1, obstacleGrid, countPathDp);

        return countPathDp[m][n];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> countPathDp(m, vector<int> (n, 0));
        return countUniquePath(m-1, n-1, obstacleGrid, countPathDp);
    }
};