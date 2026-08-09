class Solution {
private:
    vector<string> res;
    void genPar(string str, int open, int close, int n){
        if (close > open || open > n) return;
        if (open+close == 2*n){
            res.push_back(str);
            return;
        } 
        genPar(str+'(', open+1, close, n);
        genPar(str+')', open, close+1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        genPar("", 0, 0, n);

        return res;
    }
};
