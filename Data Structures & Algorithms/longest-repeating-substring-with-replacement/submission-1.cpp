class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxFreq = 0, longest = 0; 
        vector<int> count(26, 0); 

        while (r < n){
            count[s[r]-'A']++;
            maxFreq = max(maxFreq, count[s[r]-'A']);

            while ((r-l+1) - maxFreq > k){
                count[s[l]-'A']--;
                l++;
            }
                
            longest = max(r-l+1, longest);
            r++;
        }
        return longest;
    }
};
