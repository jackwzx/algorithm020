/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:

    void recurAdd(int beginIndex, vector<int>& nums, vector<vector<int>>& result){
        //terminator
        if (beginIndex >= nums.size())
        {
            result.push_back(nums);
            return;
        }
        
        for (size_t i = beginIndex; i < nums.size(); i++)
        {
            //process logic in current level
            swap(nums[beginIndex], nums[i]);

            //drill down
            recurAdd(beginIndex+1, nums, result);

            //reverse current level state
            swap(nums[i], nums[beginIndex]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;

        recurAdd(0, nums, result);

        return result;

    }
};
// @lc code=end

