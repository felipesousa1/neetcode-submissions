class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;

        for (int stone : stones ){
            maxH.push(stone);
        }

        while (maxH.size() > 1){
            int h1 = maxH.top();
            maxH.pop();
            int h2 = maxH.top();
            maxH.pop();
            if (h1 != h2) maxH.push(abs(h1-h2));
        }

        if (maxH.empty()) return 0;
        return maxH.top();
    }
};
