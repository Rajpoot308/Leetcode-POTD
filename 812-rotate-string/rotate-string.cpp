class Solution {
public:

// 2. KMP algo
    
    void findLps(vector<int>& lps, string& goal) {
        int first = 0, second = 1;
        while(second < goal.length()) {
            if(goal[first] == goal[second]) {
                lps[second] = first + 1;
                first++;
                second++;
            }
            else {
                if(first == 0) {
                    lps[second] = 0;
                    second++;
                }
                else {
                    first = lps[first-1];
                }
            }
        }
    }

    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string str = s + s;
        vector<int> lps(goal.size(), 0);

        findLps(lps, goal);

        int first = 0, second = 0;
        while(first < str.length() && second < goal.length()) {
            if(str[first] == goal[second]) {
                first++;
                second++;
            }
            else {
                if(second == 0) first++;
                else{
                    second = lps[second-1];
                }
            }
        }

        if(second == goal.length()) return true;

        return false;
    }
};