/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {

        //1 subproblem
        // problem(i,j) = min(subproblem(i,j+1), subproblem(i+1,j)) + a{i,j}

        //2 状态数组 a[i, j]

        //3 dp 方程
        // f(i,j) = min(f(i+1,j), f(i,j+1)) + a[i,j]

        vector<vector<int>> dp = grid;

        for (int i = (int)dp.size() - 1; i >= 0; i--)
        {
            int rowSize = (int)dp[i].size();

            for (int j = rowSize - 1; j >= 0; j--)
            {
                if (i == (int)dp.size() - 1 && j == rowSize - 1)
                {
                    continue;
                }
                else if (i == (int)dp.size() - 1)
                {
                    dp[i][j] += dp[i][j + 1];
                }
                else if (j == rowSize - 1)
                {
                    dp[i][j] += dp[i + 1][j];
                }
                else
                {
                    dp[i][j] += min(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

