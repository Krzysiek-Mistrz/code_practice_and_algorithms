# Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
# You must do it in place.

# Example 1:
# Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
# Output: [[1,0,1],[0,0,0],[1,0,1]]

from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0])
        
        first_row_has_zero = False
        first_col_has_zero = False
        
        for j in range(cols):
            if matrix[0][j] == 0:
                first_row_has_zero = True
                break
            
        for i in range(rows):
            if matrix[i][0] == 0:
                first_col_has_zero = True
                break
            
        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
                    
        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
                    
        if first_row_has_zero:
            for j in range(cols):
                matrix[0][j] = 0
                
        if first_col_has_zero:
            for i in range(rows):
                matrix[i][0] = 0