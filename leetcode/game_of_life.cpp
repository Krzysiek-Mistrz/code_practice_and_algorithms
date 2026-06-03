#include <vector>
#include <cmath>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int live_neighbors = 0;
                
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (i == 0 && j == 0) continue;
                        
                        int neighbor_r = r + i;
                        int neighbor_c = c + j;
                        
                        if (neighbor_r >= 0 && neighbor_r < m && neighbor_c >= 0 && neighbor_c < n) {
                            if (board[neighbor_r][neighbor_c] == 1 || board[neighbor_r][neighbor_c] == 2) {
                                live_neighbors++;
                            }
                        }
                    }
                }
                
                if (board[r][c] == 1) {
                    if (live_neighbors < 2 || live_neighbors > 3) {
                        board[r][c] = 2;
                    }
                } else {
                    if (live_neighbors == 3) {
                        board[r][c] = 3;
                    }
                }
            }
        }
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 2) {
                    board[r][c] = 0;
                } else if (board[r][c] == 3) {
                    board[r][c] = 1;
                }
            }
        }
    }
};