class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {        
        int n = hand.size();
        
        if (n % groupSize != 0) return false;
        
        vector<int> mapa(1000+1, 0);

        for (int card : hand){
            mapa[card]++;
        }

        for(int i = 0; i <= 1000; i++){
            int amount = mapa[i];
            if (amount < 0) return false;
            else if (mapa[i] > 0){
                if (i + groupSize -1 > 1000) return false;
                for (int j = 0; j < groupSize; j++){
                    mapa[i+j] -= amount;
                }
            }
        }
        
        return true;
    }
};
