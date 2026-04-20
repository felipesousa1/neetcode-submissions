class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int i = 0;
        int j = heights.size()-1;
        while (i < j){
            int menor = (min(heights[i], heights[j]) == heights [i]) ? i : j;
            maxArea = max(maxArea, heights[menor]*(j-i));
            if (menor == i){
                i++;
            }
            else j--;
        }
        return maxArea;
    }
};
