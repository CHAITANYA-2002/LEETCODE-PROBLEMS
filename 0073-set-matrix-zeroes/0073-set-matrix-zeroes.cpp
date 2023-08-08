class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1; // Initialize a variable to keep track of the first column
        
        int rows = matrix.size(); // Get the number of rows in the matrix
        int cols = matrix[0].size(); // Get the number of columns in the matrix
        
        // Step 1: Identify the rows and columns that need to be zeroed out
        
        // Loop through each row
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0)
                col0 = 0; // If the first column has a zero, mark col0 as 0
            
            // Loop through each column starting from the second column (j=1)
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0; // Use the first cell of the current row and column to mark if zero is present
                }
            }
        }
        
        // Step 2: Set the zeros based on the markers
        
        // Loop through each row in reverse order
        for (int i = rows - 1; i >= 0; i--) {
            // Loop through each column in reverse order, starting from the second column
            for (int j = cols - 1; j >= 1; j--) {
                // If the marker in either the first cell of the current row or the first cell of the current column is 0
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0; // Set the current cell to 0
                }
            }
            // If col0 is 0, set the entire first column to 0
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};
