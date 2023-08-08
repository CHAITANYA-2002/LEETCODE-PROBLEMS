class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;        // Initialize the maximum profit variable
        int minPrice = INT_MAX; // Initialize the minimum price variable
        
        // Iterate through each price in the 'prices' vector
        for (int i = 0; i < prices.size(); i++) {
            // Update the minimum price if the current price is smaller
            minPrice = min(minPrice, prices[i]);
            
            // Update the maximum profit if selling at the current price is more profitable
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        
        return maxPro; // Return the maximum profit achievable
    }
};
