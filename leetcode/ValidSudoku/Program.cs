// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// Note:
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true

using System;
using System.Collections.Generic;

public class Solution
{
    public bool IsValidSudoku(char[][] board)
    {
        // Musimy przekazać tablicę do każdej metody
        return IsValidRows(board) && IsValidColumns(board) && IsValidSquares(board);
    }

    private bool IsValidRows(char[][] board)
    {
        for (int i = 0; i < 9; i++)
        {
            HashSet<char> seen = new HashSet<char>();
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                if (seen.Contains(board[i][j])) return false;
                seen.Add(board[i][j]);
            }
        }
        return true;
    }

    private bool IsValidColumns(char[][] board)
    {
        for (int j = 0; j < 9; j++)
        {
            HashSet<char> seen = new HashSet<char>();
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] == '.') continue;
                if (seen.Contains(board[i][j])) return false;
                seen.Add(board[i][j]);
            }
        }
        return true;
    }

    private bool IsValidSquares(char[][] board)
    {
        // Przechodzimy przez 9 kwadratów (każdy zaczyna się co 3 pola)
        for (int rowOffset = 0; rowOffset < 9; rowOffset += 3)
        {
            for (int colOffset = 0; colOffset < 9; colOffset += 3)
            {
                HashSet<char> seen = new HashSet<char>();
                // Sprawdzamy konkretny kwadrat 3x3
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        char current = board[rowOffset + i][colOffset + j];
                        if (current == '.') continue;
                        if (seen.Contains(current)) return false;
                        seen.Add(current);
                    }
                }
            }
        }
        return true;
    }
}