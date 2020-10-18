#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void generate(int left, int right, int len, string str, vector<string>& res) {
        if (left == len && right == len) {
            res.push_back(str);
            return;
        }
        if (left < len) generate(left + 1, right, len, str + '(', res);
        if (right < left) generate(left, right + 1, len, str +(')'), res);
    }
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string> res;
        generate(0, 0, n, str, res);
        return res; 
    }
};
//递归调用generate时，传参是str + '('，而不是str.append('(');

