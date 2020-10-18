//对于1-n中的数字选或者不选
class Solution {
public:
    vector<int> tmp;//存放已经被选中的数字
    void dfs(int cur, int n, int k, vector<vector<int>>& res) {
        //如果被选中的和目前还剩下可选数字的个数加起来不到k，那就不用往下进行了
        if (tmp.size() + (n - cur + 1) < k) {
            return;
        }
        //如果当前数字个数为k，即一种答案，放到数组中
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        //如果当前数字超过了n，返回
        if (cur == n + 1) {
            return;
        }
        //如果选择当前这个数字，drill down
        tmp.push_back(cur);
        dfs(cur + 1, n, k, res);
        //由于tmp全局，因此先pop出来刚放入的cur，即不选择当前元素，drill down
        tmp.pop_back();
        dfs(cur + 1, n, k, res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(1, n, k, res);
        return res;
    }
};