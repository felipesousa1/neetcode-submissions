class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mapa;
        int maior_freq = 0;
        for (int num : nums){
            if (mapa.find(num) != mapa.end()) continue;
            
            int esquerda = 0;
            int direita = 0;

            if (mapa.find(num-1) != mapa.end()){
                esquerda = mapa[num-1];
            }

            if (mapa.find(num+1) != mapa.end()){
                direita = mapa[num+1];
            }

            int atual_tam = 1 + esquerda + direita;

            mapa[num] = atual_tam;
            mapa[num-esquerda] = atual_tam;
            mapa[num+direita] = atual_tam;

            if (atual_tam > maior_freq) maior_freq = atual_tam;

        }

        return maior_freq;
    }
};
