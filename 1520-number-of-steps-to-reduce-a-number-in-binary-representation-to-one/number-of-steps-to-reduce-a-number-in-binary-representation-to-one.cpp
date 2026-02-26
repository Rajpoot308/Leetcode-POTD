class Solution {
public:

// 1 bit manipulation bruteforce
    int numSteps(string s) {
        int n = s.length();

        int step = 0;
        int i = n-1;
        while(i > 0) {
            int j = i;
            int unit = 1;

            if(((s[i] - '0') & 1) == 0) {
                step++;
                i--;
            }
            else{
                while(unit == 1 && j >= 0) {
                    if(((s[j] - '0') & 1) == 0) {
                        step++;
                        s[j] = 1;
                        unit = 0;
                    }
                    else{
                        s[j] = '0';
                        j--;
                    }
                    
                    
                }
                if(j < 0) step++;
            }
        }

        if(s[0] == '0') return step+1;

        return step;
    }
};