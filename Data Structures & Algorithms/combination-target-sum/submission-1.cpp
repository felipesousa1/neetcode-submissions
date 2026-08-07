class Solution {
public:
    vector<vector<int>> res;

    void combSum (vector<int>&current, int index, int curSum, vector<int>& nums, int target){
        for (int i = index; i<nums.size(); i++){
            if (curSum + nums[i] < target){
                current.push_back(nums[i]);
                combSum(current, i, curSum+nums[i], nums, target);
                current.pop_back();
            }
            else if (curSum + nums[i] == target){
                current.push_back(nums[i]);
                res.push_back(current);
                current.pop_back();
            }
        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        combSum(current, 0, 0, nums, target);

        return res;
    }
};
