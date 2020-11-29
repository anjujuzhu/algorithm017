class Solution {
public:
   int largestLen(string s, int l, int r){
        while(l >= 0 && r < s.length() && s[l] == s[r])
            l--,r++;
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int start = 0,end = 0;
        for(int i = 0; i < s.length(); i++){
            int l = max(largestLen(s, i, i), largestLen(s, i, i + 1));
            if(l > end - start){
                start = i - ((l - 1) / 2);
                end = start + l;
            }
        }
        return s.substr(start,end-start);
    }
};