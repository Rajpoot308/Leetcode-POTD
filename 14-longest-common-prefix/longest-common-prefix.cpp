class Solution {
public:

// 1. bruteforce two pointer
    
    string longestLCP(string& s1, string& s2) {
        int i = 0, j = 0;
        string str = "";
        while (i < s1.length() && j < s2.length()) {
            if(s1[i] != s2[j]) {
                break;
            }
            str += s1[i];
            i++;
            j++;
        }
        
        return str;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        if(n == 0) return "";
        if(n == 1) return strs[0];
        string lcp = strs[0];

        for(int i = 1; i < n; i++) {

            lcp = longestLCP(lcp, strs[i]);
        }

        return lcp;
    }
};