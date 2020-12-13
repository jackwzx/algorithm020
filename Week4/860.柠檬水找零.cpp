/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        map<int, int> currentMoney = {
            {20,0},
            {10,0},
            {5,0},
        };
        for (size_t i = 0; i < bills.size(); i++)
        {
            int pay = bills[i];

            if (pay == 20)
            {
                if (currentMoney[10] >= 1 && currentMoney[5] >= 1) {
                    currentMoney[20] = currentMoney[20] + 1;
                    currentMoney[10] = currentMoney[10] -1;
                    currentMoney[5] = currentMoney[5] - 1;
                }
                else if (currentMoney[10] == 0 && currentMoney[5] >=3){
                    currentMoney[20] = currentMoney[20] + 1;
                    currentMoney[5] = currentMoney[5] - 3;
                }
                else
                {
                     return false;
                }
            }
            else if (pay == 10) {
                if (currentMoney[5] >= 1)
                {
                    currentMoney[10] = currentMoney[10]+1;
                    currentMoney[5] = currentMoney[5]-1;
                }
                else {
                    return false;
                }
                
            }
            else {
                currentMoney[5] = currentMoney[5]+1;
            }
        }

        return true;
    }
};

// @lc code=end

