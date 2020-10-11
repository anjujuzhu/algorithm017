//暴力 sort
/****O(nlogn)*****/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end()); 
        sort(t.begin(), t.end());
        return s == t;
    }
};

//数组——存放字母出现的频次
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int hash[26] = {0};
        for (auto m : s) {
            hash[m - 'a']++;
        } 
        for (auto n : t) {
            hash[n - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (hash[i] != 0) return false;
        }
        return true;
        /*
        if(s.size() != t.size()) return false;
        int hash[26] = {0}; //初始化
        for (int i = 0; i < s.size(); ++i) {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (hash[i] != 0) return false;
        }
        return true;
        */
    }
};
//哈希表
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); ++i) {
            hash[s[i]]++;
            hash[t[i]]--;
        } 
        for (auto &it : hash) {
            if (it.second != 0) return false;
        }
        return true;
    }
};