class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (string str : strs){
            string n = to_string(str.size());
            string m = to_string(n.size());
            s += m + n + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> decoded;
        int i = 0;
        while (i < n){
            int m = s[i]-'0';
            i++;
            string n_s = s.substr(i,m);
            i += m;
            int n_str = stoi(n_s);
            string str = s.substr(i,n_str);
            decoded.push_back(str);
            i += n_str;
        }
        return decoded;
    }

};
