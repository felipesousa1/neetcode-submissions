class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counts[26] = {};
        for (char task : tasks) {
            counts[task - 'A']++;
        }

        priority_queue<int> pq;

        for (int c : counts){
            if (c>0){
                pq.push(c);
            } 
        }

        queue<pair<int,int>> q;
        int time = 0;

        while (!pq.empty() || !q.empty()) {
            time++;

            if (!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
            if (!pq.empty()){
                if (pq.top() > 1) q.push({pq.top()-1, time+n+1});
                pq.pop();
            }
        }

        return time;
    }
};
