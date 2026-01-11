class Solution {
public:

// 
    // int uniquePathCounts(int m, int n) {

    //     if(m == 0 && n == 0) return 1;
    //     if(m < 0 || n < 0) return 0;

    //     int pathCounts = uniquePathCounts(m, n-1) + uniquePathCounts(m-1, n);

    //     return pathCounts;

    // }

    // int uniquePaths(int m, int n) {

    //     return uniquePathCounts(m-1, n-1);
    // }

// 2. Memoization + recursion 
    
    int uniquePathCounts(int m, int n, vector<vector<int> >& pathCountsDp) {
        
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        if(pathCountsDp[m][n] != -1) return pathCountsDp[m][n];
        
        pathCountsDp[m][n] = uniquePathCounts(m, n-1, pathCountsDp) + uniquePathCounts(m-1, n, pathCountsDp);
        
        return pathCountsDp[m][n];
    }

    int uniquePaths(int m, int n) {
        
        vector<vector<int> > pathCountsDp(m, vector<int> (n, -1));
        return uniquePathCounts(m-1, n-1, pathCountsDp);
    }
};