class Solution {
public:

// 1. bruteforce
    
    bool isPrefix(string& target, string& source) {
        int i = 0, j = 0;
        while(i < target.length() && j < source.length()) {
            if(target[i] != source[j]) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
    
    bool isPrefixString(string s, vector<string>& words) {
        
        string samStr = "";
        for(string& str : words) {
            samStr += str;

            if(!isPrefix(samStr, s)) {
                break;
            }
            if(samStr == s) return true;

        }
        return false;
    }
};