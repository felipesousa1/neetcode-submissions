class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> lastAcur;
        vector<int> res;
        
        for (int i = 0; i < n; i++){
            lastAcur[s[i]] = i;
        }

        int begin = 0;
        int end = 0;

        while (begin < n){
            end = lastAcur[s[begin]];
            for (int i = begin+1; i<=end; i++){
                end = max(end, lastAcur[s[i]]);
            }
            res.push_back(end-begin+1);
            begin = end+1;
        }

        return res;
    }
};
