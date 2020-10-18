class Solution {
public:
//时间复杂度过高，超出时间限制
    int climbStairs(int n) {
        if (n <= 2) return n;
        if (n > 2) return climbStairs(n - 1) + climbStairs(n - 2);
        return -1;
    }
};
//动态规划
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int f1 = 1, f2 = 2, fn;
        for (int i = 3; i <= n; ++i) {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};