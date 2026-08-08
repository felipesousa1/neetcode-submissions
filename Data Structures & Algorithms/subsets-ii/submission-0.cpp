class Solution {
private:
    vector<vector<int>> res;

    void sub(int index, vector<int>&cur, vector<int>& nums){
        res.push_back(cur);
        if (cur.size() == nums.size()) return;
        for (int i=index; i < nums.size(); i++){
            if (i > index && nums[i] == nums[i-1]) continue;
            
            cur.push_back(nums[i]);
            sub(i+1, cur, nums);
            cur.pop_back();
        }

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        sub(0, cur, nums);

        return res;
    }
};
