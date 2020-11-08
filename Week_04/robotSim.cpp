class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int directionX[] = {0, 1, 0, -1};//北、东、南、西
        int directionY[] = {1, 0, -1, 0};
        int currentX = 0, currentY = 0;//当前位置的坐标
        int currentDirect = 0;//当前位置的方向 0 1 2 3对应北 东 南 西
        int len = commands.size();
        int res = 0;//记录最大距离，返回值
        set<pair<int, int>> s;//记录障碍点
        for (int i = 0; i < obstacles.size(); ++i) {
            s.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }//存放障碍点

        for (int i = 0; i < len; ++i) {
            if (commands[i] == -1) {
                currentDirect = (currentDirect + 1) % 4;
            } else if (commands[i] == -2) {
                currentDirect = (currentDirect + 3) % 4;
            } else {//如果不是-1，-2,就是朝一个方向前进的数字
                for (int j = 0; j < commands[i]; ++j) {
                    int nx = currentX + directionX[currentDirect];
                    int ny = currentY + directionY[currentDirect];

                    if (s.find(make_pair(nx, ny)) == s.end()) {
                        currentX = nx;
                        currentY = ny;
                        res = max(res, currentX * currentX + currentY * currentY);
                    } else {
                        break;
                    }
                }
            }
        }
        return res;
    }
};