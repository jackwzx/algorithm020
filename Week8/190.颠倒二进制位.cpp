/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        int i=0;
        uint32_t result = 0;
        while (i<32)
        {
            result =  (result << 1) | ((n >> i) & 1) ;
            i++;
        }
        return result;
    }
};
// @lc code=end

