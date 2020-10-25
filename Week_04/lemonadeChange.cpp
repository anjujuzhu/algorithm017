/*
三种情况
    5， five++;
    10，ten++; five--;
    20, ten--; five--; || five-3
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                ++five;
            } else if (bill == 10) {
                if (five == 0) return false;
                --five;
                ++ten;
            } else {
                if (five > 0 && ten > 0) {
                    --five;
                    --ten;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
//上面的答案确保five>0的情况下做各种判断情况
//版本2 只在最后判断five是否大于0, 从而判断true or false
//高分回答
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int i : bills) {
            if (i == 5) ++five;
            else if (i == 10) --five, ++ten;
            else if (ten > 0) --ten, --five;
            else five -= 3;
            if (five < 0) return false;
        }
        return true;
    }
};