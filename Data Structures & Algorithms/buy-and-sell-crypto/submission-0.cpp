class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int compra = prices[0];
        int lucro = 0;
        for (int i = 1; i < n; i++){
            int cand = prices[i] - compra;
            if (cand < 0) {
                compra = prices[i];
            }
            else if (cand > lucro){
                lucro = cand;
            }
        }

        return lucro;
    }
};
