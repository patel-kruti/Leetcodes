# Problem: 48. Rotate Image
# Link: https://leetcode.com/problems/rotate-image/description/
# Time Complexity:O(n^2)
# Space Complexity: O(1) - In-place
# Topics: Array, Math, Matrix
# Solution:
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        # Transpose the Matrix - Switch (i, j) with (j, i) - O(n^2)
        for i in range (0, n):
            for j in range (i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # Reverse the Row - O(n^2) as each row reversal takes O(n)
        for row in matrix:
            row.reverse()

        return matrix
