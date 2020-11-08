/*
if s[i] == '(' :
    dp[i] = 0
if s[i] == ')' :
    if s[i - 1] == '(' :
        dp[i] = dp[i - 2] + 2 #要保证i - 2 >= 0

    if s[i - 1] == ')' and s[i - dp[i - 1] - 1] == '(' :
        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2 #要保证i - dp[i - 1] - 2 >= 0
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        vector<int> dp(len, 0);
        int res = 0;
        for(int i = 1; i < len; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i - 2 >= 0) {
                        dp[i] = dp[i] + dp[i - 2];
                    }
                } else if (dp[i - 1] > 0) {
                    if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if ((i - dp[i - 1] - 2) >= 0) {
                            dp[i] = dp[i] + dp[i - dp[i - 1] - 2];
                        }
                    }
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
