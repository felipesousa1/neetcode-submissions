class TimeMap {
public:
    TimeMap() {
        
    }

    unordered_map<string, vector<pair<int, string>>> time_map;
    
    void set(string key, string value, int timestamp) {
        time_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (time_map.find(key) == time_map.end()) return "";
        if (time_map[key][0].first > timestamp) return "";
        int l = 0;
        int r = time_map[key].size()-1;

        while (l<r){
            int m = l + (r - l + 1) / 2;
            if (time_map[key][m].first > timestamp) r = m - 1;
            else if (time_map[key][m].first < timestamp) l = m;
            else return time_map[key][m].second;
        }

        return time_map[key][l].second;
    }
};
