class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxSum = INT_MIN; // Variable to store the minimized maximum pair sum
        int minNum = INT_MAX; // Variable to store the minimum number in the array
        int maxNum = INT_MIN; // Variable to store the maximum number in the array

        std::vector<int> frequency(100001, 0); // Vector to store the frequency of each number in the array

        // Iterate through the array to populate frequency vector and find min and max numbers
        for (int num : nums) {
            frequency[num]++;
            minNum = std::min(minNum, num);
            maxNum = std::max(maxNum, num);
        }

        // Initialize pointers for two numbers to form pairs
        int low = minNum;
        int high = maxNum;

        // Iterate while low pointer is less than or equal to high pointer
        while (low <= high) {
            // If frequency of the number at low pointer is zero, move low pointer to the right
            if (frequency[low] == 0) {
                low++;
            }
            // If frequency of the number at high pointer is zero, move high pointer to the left
            else if (frequency[high] == 0) {
                high--;
            }
            // Both low and high pointers point to valid numbers
            else {
                // Calculate the sum of the pair at the current pointers
                int currentPairSum = low + high;
                // Update maxSum if the current pair sum is greater
                maxSum = std::max(maxSum, currentPairSum);
                // Decrease the frequency of the numbers at low and high pointers
                frequency[low]--;
                frequency[high]--;
            }
        }

        return maxSum; // Return the minimized maximum pair sum
    }
};