//双指针（一次遍历）
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for (; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                int temp = nums[j];
                nums[j++] = nums[i];
                nums[i] = temp;
            }
        }
    }
};