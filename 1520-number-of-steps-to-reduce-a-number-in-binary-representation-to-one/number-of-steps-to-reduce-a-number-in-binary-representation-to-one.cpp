class Solution {
public:

// 1 bit manipulation 
    // int numSteps(string s) {
    //     int n = s.length();

    //     int step = 0;
    //     int i = n-1;
    //     while(i > 0) {
    //         int j = i;
    //         int unit = 1;

    //         if(((s[i] - '0') & 1) == 0) {
    //             step++;
    //             i--;
    //         }
    //         else{
    //             while(unit == 1 && j >= 0) {
    //                 if(((s[j] - '0') & 1) == 0) {
    //                     step++;
    //                     s[j] = 1;
    //                     unit = 0;
    //                 }
    //                 else{
    //                     s[j] = '0';
    //                     j--;
    //                 }
                    
                    
    //             }
    //             if(j < 0) step++;
    //         }
    //     }

    //     if(s[0] == '0') return step+1;

    //     return step;
    // }


// 2. 
    void addOneToBinary(string& s, int end) {

        while(end >= 0) {
            if(s.at(end) == '0') {
                s.at(end) = '1';
                break;
            }
            s.at(end) = '0';
            end--;
        }

        if(end < 0) {
            s = '1' + s;
        }
    }

    int numSteps(string s) {
        int end = s.length() - 1;
        int steps = 0;

        while(end > 0) {
            steps++;
            if(s.at(end) == '0') {
                s.pop_back();
                end--;
            }
            else{
                addOneToBinary(s, end);
                end = s.length() - 1;
            }
        }

        return steps;
    }
};