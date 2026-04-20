class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> tempo;
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i<n; i++){
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.rbegin(), cars.rend());
        
        for(int i = 0; i < n; i++){
            double t_atual = 1.0*(target - cars[i].first) / cars[i].second;
            if (tempo.empty() || t_atual > tempo.top()) tempo.push(t_atual); 
        }

        return tempo.size();
    }
};
