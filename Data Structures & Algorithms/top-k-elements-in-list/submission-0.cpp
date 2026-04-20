class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cont[2001] = {0};
        for (int num : nums){
            cont[num+1000]++;
        }
        
        vector<int> res;

        while(k--){
            auto maiorIt = max_element(begin(cont), end(cont));
            int indice = distance(begin(cont), maiorIt);
            res.push_back(indice-1000);
            cont[indice] = 0;
        }

        return res;
    }
};
