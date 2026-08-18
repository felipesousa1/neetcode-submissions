class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int res = nums[0];

        for (int i = 1; i<nums.size(); i++){
            int cur = nums[i];
            int a = cur*maxProd;
            int b = cur*minProd;

            maxProd = max({a, b, cur});
            minProd = min({a, b, cur});

            res = max(res, maxProd);
        }

        return res;     
    }
};
