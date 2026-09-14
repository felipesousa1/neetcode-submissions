class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {        
        int n = hand.size();
        
        if (n % groupSize != 0) return false;
        
        vector<int> mapa(1000+n, 0);

        for (int card : hand){
            mapa[card]++;
        }

        for(int i = 0; i <= 1000; i++){
            if (mapa[i] < 0) return false;
            
            if (mapa[i] > 0) {
                int amount = mapa[i];
                for (int j = 0; j < groupSize; j++) {
                    mapa[i + j] -= amount;
                }
            }
        }
        
        return true;
    }
};
