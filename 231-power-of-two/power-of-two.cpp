class Solution {
public:

// 1. Using Reminder-divident method:-(T.C. - O(log(n)  S.C. - O(1)))
    // bool isPowerOfTwo(int n) {

    //     if(n==0) return false;
    //     while(n%2 == 0) n/=2;

    //     return n==1;
    // }

// 2.  Using Reminder-divident method(Recursively) T.C.- O(log(n)) S.C. O(log(n))[recursive stack]
    // bool isPowerOfTwo(int n) {
    //     if(n==0) return false;
    //     if(n==1) return true;

    //     return (n%2 == 0 && isPowerOfTwo(n/2));
    // }

// 3. Using ceil-floor method. T.C.- O(log(n)) S.C. - O(1)
    // bool isPowerOfTwo(int n) {
    //       if(n<=0) return false;
    //       return ceil(log2(n)) == floor(log2(n));
    // }

// 4. Bit manipulation. T.C. -O(1) S.C. - O(1)
    bool isPowerOfTwo(int n) {
          if(n<= 0) return false;
          return ((n&(n-1)) == 0);
    }
};