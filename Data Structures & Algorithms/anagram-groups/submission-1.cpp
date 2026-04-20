class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map < string, vector<string>> conjuntos;
        for (string s : strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());

            conjuntos[sorted].push_back(s);

        }

        vector<vector<string>> result;

        for (auto& pair : conjuntos){
            result.push_back(pair.second);
        }

        return result;
      
    }
};
