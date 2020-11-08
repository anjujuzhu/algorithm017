class Solution {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        if (m == 0) return 0;
        if (m == 1) return nums[0];
        int dp0 = 0, dp1 = 0, dpi = 0;
        for (int i = 1; i < m; ++i) {
            dpi = max(dp1, dp0 + nums[i]);
            dp0 = dp1;
            dp1 = dpi;
        }
        dp0 = 0;
        dp1 = 0;
        int dp2 = 0;
        for (int i = 0; i < m - 1; ++i) {
            dp2 = max(dp1, dp0 + nums[i]);
            dp0 = dp1;
            dp1 = dp2;
        }
        return max(dpi, dp2);
    }
};