class Solution {
public:
    vector<vector<int>> res;

    void combSum (vector<int>&current, int index, vector<int>& nums, int target){
        if (target == 0){
            res.push_back(current);
            return;
        }
        
        for (int i = index; i<nums.size(); i++){
            if (nums[i] > target) break;

            current.push_back(nums[i]);
            combSum(current, i, nums, target-nums[i]);
            current.pop_back();

        
        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        combSum(current, 0, nums, target);

        return res;
    }
};
