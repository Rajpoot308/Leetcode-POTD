class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeftCords, vector<vector<int>>& topRightCords) {
        long maxiAreaSquare = INT_MIN;
        

        for (int s = 0; s < bottomLeftCords.size(); s++) {
            for (int e = s + 1; e < topRightCords.size(); e++) {
                int la = max(bottomLeftCords[s][0], bottomLeftCords[e][0]);
                int ma = max(bottomLeftCords[s][1], bottomLeftCords[e][1]);
                int lb = min(topRightCords[s][0], topRightCords[e][0]);
                int mb = min(topRightCords[s][1], topRightCords[e][1]);

                if (la < lb && ma < mb) {
                    int sL = min(lb - la, mb - ma);
                    long area = (long) sL*sL;
                    maxiAreaSquare = max(maxiAreaSquare,area );
                }
            }
        }
        if(maxiAreaSquare == INT_MIN)  maxiAreaSquare = 0;

        return maxiAreaSquare;
    }
};