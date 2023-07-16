class Solution {
public:
    bool check(vector<int>& nums) {
        // Initialize the break variable to 1
        int breaks = 0;

        // Iterate over the len(nums)
        for(int i = 0; i < nums.size(); i++){
            // If you find any break case, increment the break variable
            if(nums[(i+1) % nums.size()] < nums[i])
                breaks++;
        }

        // If there is atmost 1 breaks, return True
        // Else, return False
        return breaks <= 1;

    }
};
