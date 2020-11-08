class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = 0, res = nums[0];
        for (auto it : nums) {
            dp = max(it, dp + it);
            res = max(res, dp);
        }
        return res;
    }
};