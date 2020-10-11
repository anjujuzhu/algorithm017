//暴力循环移位
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0;
        int len = nums.size();
        while (i < k) {
            int tmp = nums[len - 1];
            for (int j = len - 1; j > 0; --j) {
                nums[j] = nums[j-1];
            }
            nums[0] = tmp;
            ++i;
        }
    }
};
//开辟新数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> newNums(len);
        for (int i = 0; i < len; ++i) {
            newNums[(i + k) % len] = nums[i];
        }
        for (int i = 0; i < len; ++i) {
            nums[i] = newNums[i];
        }
    }
};
//环状替代
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0;
        int len = nums.size();
        for (int start = 0; count < len; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % len;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                ++count;
            } while (start != current);
        }
    }
};
//三次翻转
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while ( start < end ) {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();//测试用[-1], k = 2时,需要先将k取余数组长度
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};