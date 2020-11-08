//
class Solution {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        if (m == 0) return 0;
        vector<vector<int>> dp(m + 1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] +nums[i];
        }
        return max(dp[m - 1][0], dp[m - 1][1]);

    }
};
//
class Solution {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        if (m == 0) return 0;
        if (m == 1) return nums[0];
        vector<int> dp(m + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < m; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[m - 1];

    }
};
//
class Solution {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        int dp0 = 0, dp1 = 0, dpi = 0;
        for (int i = 0; i < m; ++i) {
            dpi = max(dp1, dp0 + nums[i]);
            dp0 = dp1;
            dp1 = dpi;
        }
        return dpi;
    }
};