class Solution {
public:

// 1 bruteforce T.C. O(n2) S.C. O(1)
    // vector<int> twoSum(vector<int>& nums, int target) {
        
    // }

// 2. using hashmap
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> look;

        for(int i = 0; i < n; i++) {
            int num = target - nums[i];
            if(look.count(num) > 0) {
                return {i, look[num]};
            }

            look[nums[i]] = i;
        }

        return {};
    }
};