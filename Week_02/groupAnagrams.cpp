#include<iostream>
#include<unordered_map>
#include<vector> 
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;
        for (int i = 0; i < strs.size(); ++i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            hash[temp].push_back(strs[i]);
        }
        for (auto& n : hash) {
            res.push_back(n.second);
        }
        return res;
    }
};
