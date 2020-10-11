//双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int j = 0;
        for (int i = 1; i < len; ++i) {
            if (nums[i] != nums[j]) {
                nums[++j] = nums[i];
            }
        }
        return ++j;
    }
};
//计算重复个数
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int i = 1;
        int len = nums.size();
        while (i < len) {
            if (nums[i] == nums[i-1]) {
                ++count;
            } else {
                nums[i - count] = nums[i];
            }
            ++i;
        }
        return len - count;
    }
};