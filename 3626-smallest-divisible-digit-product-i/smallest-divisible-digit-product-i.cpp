class Solution {
public:

// 1. T.C. O(n*totaldigit) S.C.(1)
    int smallestNumber(int n, int t) {
        
        int num = n;
        while(num >= n) {

            int product = 1;
            int temp = num;
            while(temp > 0) {
                int digi = temp%10;
                product *= digi;
                temp /= 10;
            }

            if(product%t == 0) {
                break;
            }
            num++;
        }

        return num;
    }
};