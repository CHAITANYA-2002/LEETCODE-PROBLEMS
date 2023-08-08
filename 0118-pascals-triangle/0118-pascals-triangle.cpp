class Solution {
public:
      vector<vector<int>> generate(int numRows) {
    vector<vector<int>> r(numRows); // Initialize a vector of vectors to hold Pascal's Triangle
    
    for(int i = 0; i < numRows; i++) {
        r[i].resize(i + 1); // Resize the current row to have 'i + 1' elements
        r[i][0] = r[i][i] = 1; // Set the first and last elements of the row to 1
        
        // Calculate the values for elements between the first and last
        for(int j = 1; j < i; j++) {
            // Each element is the sum of the two elements directly above it in the previous row
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
    }
    
    return r; // Return the generated Pascal's Triangle
}


};