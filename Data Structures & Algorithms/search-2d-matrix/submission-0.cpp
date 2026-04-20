class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();

        int l = 0;
        int r = M*N - 1;

        while (l <= r){
            int m = l + (r-l)/2;
            if (target > matrix[m/N][m%N]) l = m+1;
            else if (target < matrix[m/N][m%N]) r = m-1;
            else return true;
        }

        return false;
    }
};
