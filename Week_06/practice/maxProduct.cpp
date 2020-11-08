class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int ma = 0, mi = 0, res = 0;
        for (auto it : nums) {
            if (it < 0) {
                swap(ma, mi);
            }
            ma = max(it * ma, it);
            mi = min(it * mi, it);
            res = max(res, ma);
        }
        return res;
    }
};