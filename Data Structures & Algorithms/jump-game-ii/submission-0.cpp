class Solution {
public:
    int jump(vector<int>& nums) {
        int minJumps = 0;
        int l = 0; int r = 0;
        while (r < nums.size()-1){
            minJumps++;
            int newR = r+1;
            for (int i = l; i <= r; i++){
                newR = max(newR, i+nums[i]);
            }
            l = r+1;
            r = newR;
        }

        return minJumps;
    }
};
