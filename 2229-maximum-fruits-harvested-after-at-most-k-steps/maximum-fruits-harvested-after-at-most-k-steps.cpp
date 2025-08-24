class Solution {
public:
// 1. Sliding window + prefix Sum + Binary Search T.C. - O(k * logn) S.C. O(n)
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
        int n = fruits.size();
    
        vector<int> position(n);
        vector<int> prefixAmount(n);

        for(int i = 0; i < n; i++) {
            position[i] = fruits[i][0];
            prefixAmount[i] = fruits[i][1] + (i > 0 ? prefixAmount[i-1] : 0);
        }
        
        int maxHarvest = 0;
        for(int d = 0; d <= k/2; d++) {
            // 1. move left side d first
            int remain = k-2*d;
            int i = startPos - d;
            int j = startPos + remain;

            int left = lower_bound(position.begin(), position.end(), i) - position.begin();
            int right = upper_bound(position.begin(), position.end(), j) - position.begin() - 1;

            if(left <= right) {
                int totalHarvest = prefixAmount[right] - (left > 0 ? prefixAmount[left-1] : 0);
                maxHarvest = max(maxHarvest, totalHarvest);
            }
            
            

            // 2. move right side d first
            i = startPos - remain;
            j = startPos + d;

            left = lower_bound(position.begin(), position.end(), i) - position.begin();
            right = upper_bound(position.begin(), position.end(), j) - position.begin() - 1;

            if(left <= right) {
                int totalHarvest = prefixAmount[right] - (left > 0 ? prefixAmount[left-1] : 0);
                maxHarvest = max(maxHarvest, totalHarvest);
            }
        }

        return maxHarvest;
    }
};