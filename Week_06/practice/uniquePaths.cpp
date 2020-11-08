class Solution {
public:
    int uniquePaths(int m, int n) {
        int opt[m][n];
        for (int i = 0; i < n; ++i) {
            opt[0][i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            opt[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                opt[i][j] = opt[i][j - 1] + opt[i - 1][j];
            }
        }
        return opt[m-1][n-1];
    }
};
//节约存储空间
class Solution {
public:
    int uniquePaths(int m, int n) {
        int opt[n];
        for (int i = 0; i < n; ++i) {
            opt[i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                opt[j] += opt[j - 1];
            }
        }
        return opt[n-1];
    }
};
