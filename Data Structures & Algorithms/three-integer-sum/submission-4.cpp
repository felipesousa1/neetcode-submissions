class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int k = 0; k < n-2; k++){
            if (nums[k] > 0) break;

            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int i = k+1;
            int j = n-1;
            int target = -nums[k];

            while(i < j){
                int soma = nums[i]+nums[j];
                if( soma == target){
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (nums[i] == nums[i+1] && i<j) i++;
                    while (nums[j] == nums[j-1] && i<j) j--;

                    i++;
                    j--;
                }
                else if (soma < target) i++;
                else j--;
            }
            while(nums[k] == nums[k+1] && k<n-2) k++;
        }
        return res;
    }
};
