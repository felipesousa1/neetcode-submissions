class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1;
        int r = piles[piles.size()-1];
        while (l < r){
            int m = l + (r-l)/2;
            
            int c = 0;
            for (int pile : piles){
                c += ceil(1.0*pile/m);
            }

            if (c > h){
                l = m+1;
            }
            else r = m;

        }

        return l;
    }
};
