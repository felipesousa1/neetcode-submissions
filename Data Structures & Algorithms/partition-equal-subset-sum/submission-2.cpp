class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t = 0;
        for (int num : nums) t += num;
        
        if (t % 2 == 1) return false;

        t /= 2;

        vector<bool> dp(t+1, false);
        dp[0] = true;

        for (int num : nums){
            for (int i = t; i >= num; i--){
                if (dp[i - num]) dp[i] = true;
            }
        }

        return dp[t];
    }
};
