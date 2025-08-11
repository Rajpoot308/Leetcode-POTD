class Solution {
public:

// 1. Two pointer approch T.C.-O(m*(n-m)) S.C.-O(1)
    // int strStr(string haystack, string needle) {
    //     int n = haystack.length();
    //     int m = needle.length();

    //     if(n < m) {
    //         return -1;
    //     }


    //     for(int i = 0; i < n-m+1; i++){
    //         int hayIdx = i, neeIdx = 0;
    //         while(neeIdx < m){
    //             if(haystack[hayIdx] != needle[neeIdx]){
    //                 break;
    //             }
    //             hayIdx++;
    //             neeIdx++;
    //         }
    //         if(neeIdx == m){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }



// 4. two pointer approch T.C. O(m*(n-m)) S.C. O(1)
   
    // int strStr(string haystack, string needle) {
    //     int n = haystack.length();
    //     int m = needle.length();
    //     int indx = -1;

    //     // if source string (haystack) is smaller than target string (needle)
    //     if(n < m) return indx;
        
    //     int i = 0, j = 0;
    //     while(i < n && j < m) {
    //         if(haystack[i] == needle[j]) {
    //             i++;
    //             j++;
    //         }
    //         else {
    //             i = i - j + 1;
    //             j = 0;
    //         }
    //     }

    //     if(j == m) indx = i - m;

    //     return indx;


    // }

// 2. Robin-Corp Algo (hashCode is sum of mapped digit)
//    T.C.-Worst-O((n-m)*m)
    // int strStr(string haystack, string needle) {
    //     int n = haystack.length();
    //     int m = needle.length();

    //     if(n < m) {
    //         return -1;
    //     }

    //     int neeHashCode = 0;
    //     for(char &ch : needle){
    //         neeHashCode += ch-'a';
    //     }
        
    //     int hayHashCode = 0;
    //     for(int i = 0; i < m; i++){
    //         hayHashCode += haystack[i]-'a';
    //     }
    //     if(hayHashCode == neeHashCode){
    //         for(int i = 0; i < m; i++){
    //             if(haystack[i] != needle[i]){
    //                 break;
    //             }

    //             if(i == m-1){
    //                 return 0;
    //             }
    //         }
    //     }

    //     for(int  i = m; i < n; i++){
    //         hayHashCode += (haystack[i]-'a') - (haystack[i - m]-'a');

    //         if(hayHashCode == neeHashCode){
    //             // we have to perform this extra checking due to which T.C. is become n*m
    //             int k = i-m+1;
    //             for(int j = 0; j < m; j++){
    //                 if(haystack[k++] != needle[j]){
    //                     break;
    //                 }

    //                 if(j == m-1){
    //                     return i-m+1;
    //                 }
    //             }
    //         }
    //     }
    //     return -1;

    // }

// 3. (original) Robin-Corp Algo (hashCode is )
    // int strStr(string haystack, string needle) {

    // }


// 2. by using the string function (find())
    // int strStr(string haystack, string needle) {

    //     //check the length of mainStr and subStr
    //         if(haystack.length()<needle.length()){
    //             return -1;
    //         }
            
    //         size_t found=haystack.find(needle);
    //         if(found!=string::npos){
    //                 return found;
    //         }

    //         return -1;  
    // }  
            

// 4. sliding window technique(T.C.--O(n*m))  S.C.- O(1)
    // int strStr(string haystack, string needle) {

    //     int n=haystack.length();
    //     int m=needle.length();

    //     for(int i=0;i<n-m;i++){
    //         for(int j=0;j<m;j++){
    //             if(needle[j]!=haystack[i+j]){
    //                 break;
    //             }
    //             if(j==m-1){
    //                 return i;
    //             }
    //         }
    //     }
    //     return -1;

    // }


// 5. LPS approch and string matching algo
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // if source string ie haystack is smaller than target string ie needle
        if(n < m) {
            return -1;
        }
        
        // make the lps of target string ie needle
        vector<int> lps(m, 0);
        int i = 0, j = 1;
        while(j < m) {
            if(needle[i] == needle[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            }
            else {
                if(i == 0) {
                    lps[j] = 0;
                    j++;
                }
                else{
                    i = lps[i-1];
                }
            }
        }

        // compare target string (needle) with source string (haystack)
        i = 0;
        j = 0;
       
        while(i < n && j < m){
            if(haystack[i] != needle[j]){
                if(j == 0) {
                    i++;
                }
                else {
                    j = lps[j-1];
                }
            }
            else {
                i++;
                j++;
            }
        }
        if(j == m){
           return i - m;
        }
            
        return -1;
    }



};