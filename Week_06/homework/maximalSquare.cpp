class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
         if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSide = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    
                        maxSide  = max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};