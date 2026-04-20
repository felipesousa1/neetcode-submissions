class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> pilha;
        vector<int> res(n,0);
        for (int i = 0; i < n; i++){
            
            while(!pilha.empty() && temperatures[pilha.top()] < temperatures[i]){
                res[pilha.top()] = i - pilha.top();
                pilha.pop();
            }
            pilha.push(i);
        }

        return res;
    }
};
