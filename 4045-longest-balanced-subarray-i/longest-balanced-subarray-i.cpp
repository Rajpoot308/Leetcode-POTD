class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int len = 0;

        // Try all subarrays starting at i
        for (int i = 0; i < n; i++) {
            unordered_set<int> odd, even; // store distinct values

            for (int j = i; j < n; j++) {
                // classify current element
                if (nums[j] % 2 == 0)
                    even.insert(nums[j]);
                else
                    odd.insert(nums[j]);

                // check balance condition
                if (odd.size() == even.size())
                    len = max(len, j - i + 1);
            }
        }
        return len;
    }
};