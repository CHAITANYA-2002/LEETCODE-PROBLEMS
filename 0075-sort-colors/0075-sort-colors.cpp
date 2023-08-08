class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;      // Count of red color (0)
        int white = 0;    // Count of white color (1)
        int blue = 0;     // Count of blue color (2)
        
        // Count the occurrences of each color
        for (int num : nums) {
            if (num == 0) red++;       // Increment red count if the color is red (0)
            else if (num == 1) white++; // Increment white count if the color is white (1)
            else if (num == 2) blue++;  // Increment blue count if the color is blue (2)
        }
        
        // Modify the original array with the sorted colors
        for (int i = 0; i < nums.size(); i++) {
            if (red > 0) {
                nums[i] = 0; // Place red color (0) if there are remaining red counts
                red--;       // Decrement the red count
            } else if (white > 0) {
                nums[i] = 1; // Place white color (1) if there are remaining white counts
                white--;     // Decrement the white count
            } else if (blue > 0) {
                nums[i] = 2; // Place blue color (2) if there are remaining blue counts
                blue--;      // Decrement the blue count
            }
        }
    }
};
