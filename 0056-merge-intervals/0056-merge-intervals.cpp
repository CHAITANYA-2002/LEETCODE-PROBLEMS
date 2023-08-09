class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> result; // Initialize a vector to store the merged intervals

        // Base case: Return an empty result if there are no intervals
        if (interval.size() == 0) return result;

        // Sort the intervals based on their starting points (takes O(n log n) time)
        sort(interval.begin(), interval.end());

        // Insert the first interval into the result vector
        result.push_back(interval[0]);

        int j = 0; // Initialize a pointer to the last interval in the result vector

        // Traverse through the entire interval vector (takes O(n) time)
        for (int i = 1; i < interval.size(); i++) {
            // If the current interval overlaps with the last interval in the result
            if (result[j][1] >= interval[i][0]) {
                // Update the end point of the last interval to the maximum of the two end points
                result[j][1] = max(result[j][1], interval[i][1]);
            }
            // If the current interval doesn't overlap
            else {
                j++; // Move the pointer to the next interval in the result
                result.push_back(interval[i]); // Add the current interval to the result
            }
        }

        return result; // Return the merged intervals
    }
};
