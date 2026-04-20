class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mapa;
        for (int i = 0; i < n; i++ ){
            if (mapa.find(target-nums[i]) != mapa.end()){
                return {mapa[target-nums[i]],i};
            }
            else mapa[nums[i]] = i;
        }        
    }
};
