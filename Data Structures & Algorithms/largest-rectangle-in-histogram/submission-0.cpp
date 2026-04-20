class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> pilha;
        
        vector<int> m_esq(n,-1);
        for (int i = 0; i < n; i++){
            while (!pilha.empty() && heights[pilha.top()] >= heights[i]){
                pilha.pop();
            }
            if (!pilha.empty()){
                m_esq[i] = pilha.top();
            }
            pilha.push(i);
        }

        while (!pilha.empty()) pilha.pop();

        vector<int> m_dir(n,n);
        for (int i = n-1; i >= 0; i--){
            while (!pilha.empty() && heights[pilha.top()] >= heights[i]){
                pilha.pop();
            }
            if (!pilha.empty()){
                m_dir[i] = pilha.top();
            }
            pilha.push(i);
        }

        int max_area = 0;
        for (int i = 0; i < n; i++){
            int area_atual = (m_dir[i]-m_esq[i]-1)*heights[i];
            if (area_atual > max_area) max_area = area_atual;
        }

        return max_area;

    }
};
