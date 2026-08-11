class Solution {
private:
    int dist(const vector<int>& a){
        return a[0]*a[0]+a[1]*a[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        for(const auto& point : points){
            int priority = dist(point);
            pq.push({priority, point});

            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
