class Solution {
private:
    vector<vector<int>> res;

    void combSum2(vector<int>&cur, int index, vector<int>& candidates, int target ){
        if (target == 0){
            res.push_back(cur);
            return;
        }
        for (int i = index; i < candidates.size(); i++){
            if (target - candidates[i] < 0) break;

            if (i > index && candidates[i] == candidates[i - 1]) continue;

            cur.push_back(candidates[i]);
            combSum2(cur, i+1, candidates, target-candidates[i]);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        combSum2(cur, 0, candidates, target);
        return res;
    }
};
