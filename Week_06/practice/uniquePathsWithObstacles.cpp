//开辟一维数组存储中间状态
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector <int> opt(col);//初始化都为0
        opt[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    opt[j] = 0;
                } else if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    //这里的else if后只判断j - 1 > 0也可以，为了保证opt[j - 1]索引有效
                    //这里判断obstacleGrid[i][j - 1] == 0即剪枝，因为如果!= 0，则opt[j - 1] == 0
                    //初始化中opt[x]都是为0，那opt[j] += opt[j - 1]依旧为0
                    //因此加上这个判断条件，耗时减小
                    opt[j] += opt[j - 1];
                }
            }
        }
        return opt.back();
    }
};

//二维数组
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;//这里用二维数组，初始化dp[0][1] = 1是因为创建数组时初始化都为0
        //初始状态dp[1][1] = 1；但是根据dp方程,dp[1][1]需要在for循环里算出，因此将dp[0][1] = 1
        //或者将dp[1][0]设置为1也可，两者有一个为1，保证了初始状态为1
        //注意这里返回的事dp[m][n]
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};