class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minP = 0;
        int maxSum = INT_MIN;
        int t = 0;
        for (int num : nums){
            t += num;
            maxSum = max(t - minP, maxSum);
            minP = min(minP, t);
        }

        return maxSum;
    }
};
