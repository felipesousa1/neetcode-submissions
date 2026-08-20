class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int prev1 = 1;
        int prev2 = 1;

        for (int i = 1; i < s.size(); i++){
            int cur = 0;
            
            if (s[i] != '0') cur += prev1;

            int num = (s[i-1]-'0')*10 + (s[i]-'0');
            if (num >= 10 && num <= 26) cur += prev2;

            if (cur == 0) return 0;

            prev2 = prev1;
            prev1 = cur;            
        }

        return prev1;
    }
};
