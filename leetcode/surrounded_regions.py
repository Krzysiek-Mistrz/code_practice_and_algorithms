# 130. Surrounded Regions
# You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
# Connect: A cell is connected to adjacent cells horizontally or vertically.
# Region: To form a region connect every 'O' cell.
# Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
# To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

# Example 1:
# Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
# Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

# Explanation:
# In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

from typing import List


class Solution:
    def solve(self, board: list[list[str]]) -> None:
        """
        Modyfikuje planszę w miejscu (in-place).
        """
        if not board or not board[0]:
            return

        rows, cols = len(board), len(board[0])

        def dfs(r: int, c: int):
            if r < 0 or r >= rows or c < 0 or c >= cols or board[r][c] != "O":
                return
            
            board[r][c] = "T"
            
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

        for r in range(rows):
            for c in range(cols):
                is_edge = r in [0, rows - 1] or c in [0, cols - 1]
                if is_edge and board[r][c] == "O":
                    dfs(r, c)

        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "O":
                    board[r][c] = "X"
                elif board[r][c] == "T":
                    board[r][c] = "O"