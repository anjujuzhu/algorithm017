class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> road(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({start, 0});

        while (!q.empty()) {
            if (q.front().first == end) {
                return q.front().second;
            }
            string str = q.front().first;
            int step = q.front().second;
            q.pop();
            for (int i = 0; i < str.size(); ++i) {
                char tmp = str[i];
                for (auto it : "ACGT") {
                    if (str[i] == it) continue;
                    str[i] = it;
                    if (road.find(str) != road.end()) {
                        q.push({str, step + 1});
                        road.erase(str);
                    }
                }
                str[i] = tmp;
            }
        }
        return -1;
    }
};