class Solution {
private: 
    int res = 0;
    void validPal(const string& s, int l, int r){
        int n = s.size();
        while(l>=0 && r < n){
            if (s[l] != s[r]) return;
            res++;
            l--; r++;
        }

    }
public:
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++){
            validPal(s, i, i);
            validPal(s, i, i+1);
        }

        return res;
    }
};
