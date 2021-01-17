/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
    bool isAbc(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        }
        return false;
    }
    
    string reverseOnlyLetters(string S) {
        
        int i = 0;
        int j = (int)S.length() - 1;
        
        while (i < j) {
            if (!isAbc(S[i])) {
                i++;
                continue;
            }
            if (!isAbc(S[j])) {
                j--;
                continue;
            }
            swap(S[i++], S[j--]);
        }
        return S;
    }
};
// @lc code=end

