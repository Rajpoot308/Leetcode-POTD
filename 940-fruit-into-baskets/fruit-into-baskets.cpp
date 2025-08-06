class Solution {
public:
// 1.
    int totalFruit(vector<int>& fruits) {
        int maxFruit = 0;
        int i = 0;
        unordered_map<int, int> fruitFreq;

        for(int j = 0; j < fruits.size(); j++) {
            fruitFreq[fruits[j]]++;

            while(fruitFreq.size() > 2) {
                fruitFreq[fruits[i]]--;

                if(fruitFreq[fruits[i]] == 0) {
                    fruitFreq.erase(fruits[i]);
                }
                i++;
            }
            maxFruit = max(maxFruit, j-i+1);
        }

        return maxFruit;
    }
};