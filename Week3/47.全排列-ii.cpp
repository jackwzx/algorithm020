/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
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
        
        set<int> visited;

        for (size_t i = beginIndex; i < nums.size(); i++)
        {
            if (find(visited.begin(), visited.end(),nums[i]) != visited.end())
            {
                continue;
            }

            visited.insert(nums[i]);

            //process logic in current level
            swap(nums[beginIndex], nums[i]);

            //drill down
            recurAdd(beginIndex+1, nums, result);

            //reverse current level state
            swap(nums[i], nums[beginIndex]);
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        recurAdd(0, nums, result);

        return result;

    }
};

// @lc code=end

