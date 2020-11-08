//反向贪心
    //达到最后一个位置，要想最少的跳跃次数，前一步就是离末尾最远的位置
    //超时
int jump(vector<int>& nums) {
    int step = 0;
    int pos = nums.size() - 1;
    while (pos) {
        for (int i = 0; i < pos; ++i) {
            if (i + nums[i] >= pos) {
                ++step;
                pos = i;
                break;
            }
        }
    }
    return step;
}
//正向贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int jump_idx = 0;   //用来记录再次起跳的位置
        int max_pos = 0;
        int len = nums.size();
        //不用考虑从最后一个位置起跳的情况，所以i < nums.size()-1，而不是i < nums.size()
        for (int i = 0; i < len-1; ++i){ 
            max_pos = max(max_pos, nums[i]+ i);
            // 会不会一直迭代下去？什么时候停止++steps？
            // 隐藏的边界条件，i < len - 1 ==> jump_idx < len - 1; 所以jump_idx超出len - 1以后，结果就定下来了
            if (i == jump_idx) {        //i到达起跳位置
                jump_idx = max_pos;     //下次起跳位置设置为本次贪心计算得到的最远距离处
                ++steps;
                if (jump_idx >= len-1) {    //优化：起跳点达到或者超过终点就可以结束循环了
                    break;
                }
            }
        }
        return steps;
    }
};