class Solution {
public:

// 1. bruteforce
    
    // bool isPrefix(string& target, string& source) {
    //     int i = 0, j = 0;
    //     while(i < target.length() && j < source.length()) {
    //         if(target[i] != source[j]) {
    //             return false;
    //         }
    //         i++;
    //         j++;
    //     }
    //     return true;
    // }
    
    // bool isPrefixString(string s, vector<string>& words) {
        
    //     string samStr = "";
    //     for(string& str : words) {
    //         samStr += str;

    //         if(!isPrefix(samStr, s)) {
    //             break;
    //         }
    //         if(samStr == s) return true;

    //     }
    //     return false;
    // }

// 2. length of concatinated of k strings in words must exactly equal to the length of the s string
    bool isPrefixString(string s, vector<string>& words) {
        int n = s.length();
        string samStr = "";

        for(string& str : words) {
            samStr += str;
            if(samStr.size() > n) break;
            if(samStr == s) return true;

        }

        return false;
    
    }
};