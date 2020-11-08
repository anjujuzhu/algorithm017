class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int left = 0, right = num / 2;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long res = mid * mid;
            if (res < num) {
                left = mid + 1;
            } else if (res > num) {
                right = mid - 1;
            } else return true;
        }
        return false;
    }
};