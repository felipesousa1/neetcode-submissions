class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> chars;

        for (char c : s){
            if (chars.find(c) == chars.end()){
                chars.insert({c, 1});
            }
            else chars[c] = chars[c] + 1;
        }

        for (char d : t){
            if (chars.find(d) == chars.end()) return false;
            if (chars[d] == 1) chars.erase(d);
            else chars[d] = chars[d] - 1;
        }

        return true;
    }
};
