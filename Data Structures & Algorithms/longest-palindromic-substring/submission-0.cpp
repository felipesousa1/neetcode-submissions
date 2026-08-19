class Solution {
private:
    void longPal (const string& s, int l, int r, int&res, int& maxLen){
        int n = s.size();
        while(l>=0 && r < n && s[l] == s[r]){
            if (r-l+1 > maxLen){
                res = l;
                maxLen = r-l+1;
            }
            l--; r++;
        }
    }
public:
    string longestPalindrome(string s) {
        int res = 0;
        int maxLen = 1;
        
        for (int i = 0; i < s.size(); i++){
            longPal(s, i, i, res, maxLen);
            longPal(s, i, i+1, res, maxLen);
        }

        return s.substr(res, maxLen);
    }
};
