class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> pre(n);
        vector<int> suf(n);

        int pre_atual = height[0];
        for (int i = 1; i < n-1; i++){
            pre[i] = pre_atual;
            pre_atual = max(pre_atual, height[i]);
        }

        int suf_atual = height[n-1];
        for (int i = n-2; i> 0; i--){
            suf[i] = suf_atual;
            suf_atual = max(suf_atual, height[i]);
        }

        int area_total = 0;
        for (int i = 1; i < n-1; i++) {
            area_total += max(0, min(pre[i], suf[i])-height[i]);
        }

        return area_total;
    }
};
