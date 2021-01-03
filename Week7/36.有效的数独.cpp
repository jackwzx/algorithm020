/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int row[9][10] = {0};
        int col[9][10] = {0};
        int box[9][10] = {0};
        
        for (int i=0; i<board.size(); i++) {
            
            for (int j=0; j<board[i].size(); j++) {
                
                if (board[i][j] == '.') {
                    continue;
                }
                
                int currentNumber = board[i][j] - '0';
                
                if (row[i][currentNumber] == 1) {
                    return false;
                }
                if (col[j][currentNumber] == 1) {
                    return false;
                }
                
                int boxNumber = j/3 + i/3 * 3;
                if (box[boxNumber][currentNumber] == 1) {
                    return false;;
                }
                
                row[i][currentNumber] = 1;
                col[j][currentNumber] = 1;
                box[boxNumber][currentNumber] = 1;
            }
        }
        return true;
    }
    
};
// @lc code=end

