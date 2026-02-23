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
    // bool containsDuplicate(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());

    //     for(int i = 1; i < n; i++) {
    //         if(nums[i] == nums[i-1])
    //          return true;
    //     }

    //     return false;
    // }

// 3. using hashset T.C. O(n) S.C. O(n)
    bool containsDuplicate(vector<int>& nums) {
       int n = nums.size();
       unordered_set<int> look;
       for(int num : nums) {
          if(look.count(num) > 0) 
            return true;

            look.insert(num);
       }

       return false;
    }

// 4. using hash map 
    // bool containsDuplicate(vector<int>& nums) {
    //    int n = nums.size();
    //    unordered_map<int> look;
    //    for(int num : nums) {
    //       if(look.count(num) > 0) 
    //         return true;
    //    }

    //    return false;
    // }

};