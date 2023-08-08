class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size(); // Get the size of the matrix (number of rows/columns)
        
        // Transpose the matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                swap(m[i][j], m[j][i]); // Swap elements symmetrically across the main diagonal
            }
        }
        
        // Reverse each row to complete the rotation
        for(int i = 0; i < n; i++) {
            reverse(m[i].begin(), m[i].end()); // Reverse the elements in each row
        }
    }
};
