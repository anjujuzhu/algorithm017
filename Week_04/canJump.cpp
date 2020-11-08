/*
如果i位置数值为nums[i]，那i之后nums[i]个位置都可以做为起跳点
不断更新边界，遍历i，如果i大于最大边界，则false
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
//dfs，维护一个数组记各个位置的true or false，超出时间限制
class Solution {
public:
    void dfs(vector<int>& nums, int level, int res[]) {
        if (level >= nums.size()) return;
        res[level] = 1;
        if (nums[level] == 0) return;
        for (int i = 1; i <= nums[level] && level + i < nums.size(); ++i) {
            dfs(nums, level + i, res);
        }
    }
    bool canJump(vector<int>& nums) {
        int res[nums.size()];
        dfs(nums, 0, res);
        return res[nums.size() - 1] == 1;
    }
};
