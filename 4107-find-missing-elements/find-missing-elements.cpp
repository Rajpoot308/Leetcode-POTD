class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int lower = *min_element(nums.begin(), nums.end());
        int upper = *max_element(nums.begin(), nums.end());

        int size = upper - lower + 1;
        vector<int> hash(size, 0);

        for(int i = 0; i < size; i++) {
            
            if(i < n) {
                hash[nums[i] - lower] = 1;
            }
        }

        for(int i = 0; i < size; i++) {
            
            if(hash[i] == 0) {
                ans.push_back(i + lower);
            }
        }
        return ans;
    }
};