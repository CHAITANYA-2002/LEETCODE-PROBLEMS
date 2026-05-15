class Solution:
    def rotate(self, matrix):

        n = len(matrix)

        # transpose the matrix
        for i in range(n):

            for j in range(i, n):

                # swapping rows with columns
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # reverse every row
        for row in matrix:

            # reverse current row
            row.reverse()