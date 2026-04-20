class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while (l < r){
            int m = l + (r-l)/2;
            
            if (nums[m] > nums[r]) l = m+1;
            else r = m; 
        }

        if (target >= nums[r] && target <= nums[n-1]) r = n-1;
        else l = 0;

        while (l <= r){
            int m = l + (r-l)/2;
            if (target < nums[m]) r = m-1;
            else if (target > nums[m]) l = m+1;
            else return m;
        }

        return -1;
    }
};
