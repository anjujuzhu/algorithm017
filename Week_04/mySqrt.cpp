//二分法
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long) mid * mid <= x) {
                left = mid + 1;//小于在右半边
            } else {
                right = mid - 1;//大于在左半边
            }
        }
        return right;
    }
};
//牛顿迭代法
    /*细节：
    *   迭代点的初值x0从x开始迭代，迭代公式 1/2 * (x0 + x/x0)
    *   f(x) = x2 - C; 有两个零点-sqrt(C) && sqrt(C)，如果初值过小，可能会迭代到-sqrt(C)
    *   因此将初值设置为x
    */
        
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                return int(x0);
            }
            x0 = xi;            
        }
    }
};
