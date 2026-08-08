class Solution {
private:
    vector<vector<int>> res;
    void perm (vector<int>& cur, unordered_map<int, bool>& visited, vector<int>& nums){
        if (cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (!visited[nums[i]]){
                cur.push_back(nums[i]);
                visited[nums[i]] = true;
                perm(cur, visited, nums);
                visited[nums[i]] = false;
                cur.pop_back();
            }
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> visited;

        for (int i = 0; i<nums.size(); i++){
            visited[nums[i]] = false;
        }
        vector<int> cur;
        perm(cur, visited, nums);

        return res;
    }
};
