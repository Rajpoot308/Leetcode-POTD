class Solution {
public:

// 1. using hashmap 
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> target(26);
        for(char& ch : ransomNote) {
            target[ch - 'a']++;
        }

        for(char& ch : magazine) {
            target[ch - 'a']--;
        }

        for(int& val : target) {
            if(val > 0) return false;
        }

        return true;


    }
};