//哈希表统计频次，堆用来排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (auto i:nums) {
            hash[i]++;
        }
        priority_queue<pair<int, int>> heap;
        for (auto it : hash) {
            heap.push(make_pair(it.second, it.first));
        }
        for (int i = 0; i < k; ++i) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};