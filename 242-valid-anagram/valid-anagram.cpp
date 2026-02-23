class Solution {
public:

// 1. 
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int> target(26);
        for(char& ch : s) {
            target[ch - 'a']++;
        }

        for(char& ch : t) {
            target[ch - 'a']--;
        }

        for(int& val : target) {
            if(val != 0) return false;
        }

        return true;
    }

};