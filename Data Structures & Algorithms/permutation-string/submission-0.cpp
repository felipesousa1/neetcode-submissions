class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> right(26,0), mapa(26,0);

        int i = 0;
        for (; i < n; i++){
            right[s1[i]-'a']++;
            mapa[s2[i]-'a']++;
        }

        for (; i< m; i++){
            if (mapa == right) return true;
            mapa[s2[i]-'a']++;
            mapa[s2[i-n]-'a']--;
        }

        return (mapa == right);
    }
};
