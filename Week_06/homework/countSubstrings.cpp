class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length(), c = 0;
        vector<vector<int>> a(l, vector<int>(l,0));
        for(int i = 0; i < l; i++){
            a[i][i] = 1; 
            c++;
        }
        for(int i = 1; i < l; ++)
        {
            for(int j = 0; j < i ;j++)
            {
                if(j + 1 == i && s[j] == s[i]) {
                    a[j][i]=1;c++;
                } else {
                    if(a[j + 1][i - 1] == 1 && s[i] == s[j]) {
                        a[j][i] = 1;
                        c++;
                    }
                }
            }
        }
        return c;
    }
};