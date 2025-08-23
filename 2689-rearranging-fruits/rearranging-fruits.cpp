class Solution {
public:

// 1. T.C. O(nlogn) S.C. O(n)
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
       unordered_map<int, int> freqCount;
       int minCost = INT_MAX;

       for(auto &b1 : basket1) {
         freqCount[b1]++;
         minCost = min(minCost, b1);
       }

       for(auto &b2 : basket2) {
         freqCount[b2]--;
         minCost = min(minCost, b2);
       }
       
       vector<int> extraFruit;
       for(auto &f : freqCount) {
          int cost = f.first;
          int count = f.second;

          if(abs(count)%2 != 0) return -1;

          for(int i = 0; i < abs(count)/2; i++) {
            extraFruit.push_back(cost);
          }

       }

    //    sort(extraFruit.begin(), extraFruit.end());
       // in place of sort whole array we can only sort upto half of an array 
    //    it reduce the T.C. to O(n)
       nth_element(extraFruit.begin(), extraFruit.begin()+extraFruit.size()/2, extraFruit.end());

       long long totalCost = 0;
       
       for(int i = 0; i < extraFruit.size()/2; i++) {
          totalCost += min(extraFruit[i], 2*minCost);
       }

       return totalCost;
    }
};