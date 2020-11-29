/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string>> result;
    unordered_map<string, vector<string>> map;

    for(auto &key : strs) {
        string str = key;
        sort(key.begin(), key.end());

        if (map.find(key) == map.end())
        {
            vector<string> oriStrVec;
            map[key] = oriStrVec;
        }
        map[key].push_back(str);
    }

    for (auto &pair : map) {
        result.push_back(pair.second);
    }
    return result;

    }
};
// @lc code=end

/*
    1 建立hash_map, key为排序后的str，value为原始字符串vector
    2 遍历hash_map, 将value的数组构建成一个二维数组
*/



