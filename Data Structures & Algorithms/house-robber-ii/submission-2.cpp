class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp0(n);
        vector<int> dpNo0(n);

        dp0[0] = 0; dp0[1] = nums[0]; 
        dpNo0[0] = 0; dpNo0[1] = 0; 

        for (int i = 2; i<n; i++){
            dp0[i] = max(dp0[i-1], dp0[i-2]+nums[i-1]); 
            dpNo0[i] = max(dpNo0[i-1], dpNo0[i-2]+nums[i-1]); 
        }

        return max(dp0[n-1], dpNo0[n-2]+nums[n-1]);
    }
};
