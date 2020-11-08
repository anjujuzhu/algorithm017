//贪心算法
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); ++i) {
            if (j >= g.size()) break;
            if (s[i] >= g[j]) {
                ++j;
            }
        }
        return j;
    }
};