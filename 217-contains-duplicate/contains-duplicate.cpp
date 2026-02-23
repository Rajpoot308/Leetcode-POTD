class Solution {
public:

// 1. bruteforce T.C. O(n2) S.C. O(1) 
    // bool containsDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     for(int i = 0; i < n-1; i++) {
    //         for(int j = i+1; j < n; j++) {
    //             if(nums[i] == nums[j])
    //                return true;
    //         }
    //     }

    //     return false;
    // }

// 2. sorting T.C. O(nlogn) S.C. O(1)
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1])
             return true;
        }

        return false;
    }

};