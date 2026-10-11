class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res;
        int carry = 1;
        for (int i = n-1; i>=0; i--){
            if (carry == 0) res.push_back(digits[i]);
            else{
                if (digits[i] == 9){
                    res.push_back(0);
                }
                else{
                    res.push_back(digits[i]+1);
                    carry = 0;
                }
            }
        }

        if (carry == 1) res.push_back(1);

        reverse(res.begin(), res.end());

        return res;
    }
};
