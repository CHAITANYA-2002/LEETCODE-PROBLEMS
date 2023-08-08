class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;         // Variable to keep track of the current subarray sum
        int maxi = INT_MIN;  // Variable to store the maximum subarray sum found so far
        
        // Loop through each element in the 'nums' vector using a range-based loop
        for(auto it : nums) {
            sum += it;         // Add the current element to the 'sum'
            maxi = max(sum, maxi);  // Update 'maxi' with the maximum of 'sum' and 'maxi'
            
            if(sum < 0) {
                sum = 0;  // If 'sum' becomes negative, reset it to 0
            }
        }
        
        return maxi;  // Return the maximum subarray sum
    }
};
