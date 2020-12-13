/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

struct compare //重写仿函数
{
    bool operator()(pair<int, int>& lft, pair<int, int>& right){
    return lft.second > right.second;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> hash_map;

        for (size_t i = 0; i < nums.size(); i++)
        {
            int value = nums[i];
            hash_map[value] = ++hash_map[value];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> queue;

        for(auto map_pair : hash_map) {
            queue.push(map_pair);

            if (queue.size()>k)
            {
                queue.pop();
            }
        }

        vector<int> result;
        result.reserve(k);

        while (queue.size() > 0)
        {
            auto& element = queue.top();
            result.push_back(element.first);
            queue.pop();
        }

        return result;
    }
};
// @lc code=end

/*

1 hash_map，讲频率统计出来
2 构建大顶堆，按map的Value
3 pop前k个数字
*/

