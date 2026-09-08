class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0;
        int tank = 0;
        int curTank = 0;
        for (int i = 0; i < gas.size(); i++){
            int cur = gas[i]-cost[i];
            tank += cur;
            curTank += cur;

            if (curTank < 0){
                curTank = 0;
                res = i+1;
            }
        }

        return tank >= 0 ? res : -1;
    }
};
