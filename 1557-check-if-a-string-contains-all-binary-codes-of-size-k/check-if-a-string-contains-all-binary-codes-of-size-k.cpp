class Solution {
public:

// 1. using hashset
    
    int findPow(int k) {
        int pw = 1;
        while(k--) {
            pw *= 2;
        }
        return pw;
    }

    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string> uset;

        for(int i = 0; i < n-k+1; i++) {
            uset.insert(s.substr(i, k));
        }

        if(uset.size() == findPow(k)) {
            return true;
        }
        return false;
    }
};