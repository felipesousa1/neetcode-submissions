class Solution {
public:
    vector<vector<int>> res;

    void subset(vector<int>&current, int index, vector<int>& nums){
        res.push_back(current);

        for (int i = index; i < nums.size(); i++){
            current.push_back(nums[i]);
            subset(current, i+1, nums);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;

        subset(current, 0, nums);

        return res;
    }
};
