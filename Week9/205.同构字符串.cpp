/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;
        
        for (int i=0; i<s.length(); i++) {
            
            if (sMap.count(s[i]) && sMap[s[i]] != t[i]) {
                return false;
            }
            if (tMap.count(t[i]) && tMap[t[i]] != s[i]) {
                return false;
            }
                
            sMap[s[i]] = t[i];
            tMap[t[i]] = s[i];
        }
        return true;
    }
};
// @lc code=end

