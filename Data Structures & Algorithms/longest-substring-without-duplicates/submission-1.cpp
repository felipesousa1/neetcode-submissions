class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mapa;
        int begin = 0;
        int maior = 0;
        
        for (int i = 0; i < s.size(); i++){
            if (mapa.find(s[i]) != mapa.end() && mapa[s[i]] >= begin){
                begin = mapa[s[i]] + 1;
            }

            mapa[s[i]] = i;

            maior = max(maior, i - begin +1);
        }
        
        return maior;
    }

};
