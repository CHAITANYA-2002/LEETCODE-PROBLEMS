class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        int i = m - 1; // Pointer for n1's last element
        int j = n - 1; // Pointer for n2's last element
        int t = n + m - 1; // Pointer for the merged array's last position

        // Start iterating while there are elements in n2 to be merged
        while (j >= 0) {
            // If n1 has more elements and the current n1 element is greater than the current n2 element
            // Assign the larger n1 element to the merged array position and decrement pointers
            if (i >= 0 && n1[i] > n2[j]) {
                n1[t--] = n1[i--];
            } 
            // If n2's current element is greater than n1's current element or n1 is exhausted
            // Assign the n2 element to the merged array position and decrement pointers
            else {
                n1[t--] = n2[j--];
            }
        }
    }
};
