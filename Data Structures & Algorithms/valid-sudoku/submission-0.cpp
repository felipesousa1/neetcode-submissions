class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //verifica linhas
        for (int i = 0; i<9; i++){
            unordered_set<char> linha;
            for (int j = 0; j<9; j++){
                if (board[i][j] != '.'){
                    if (linha.find(board[i][j]) == linha.end()){
                        linha.insert(board[i][j]);
                    }
                    else return false;
                }

            }
        }
        // verifica colunas
        for (int i = 0; i<9; i++){
            unordered_set<char> coluna;
            for (int j = 0; j<9; j++){
                if (board[j][i] != '.'){
                    if (coluna.find(board[j][i]) == coluna.end()){
                        coluna.insert(board[j][i]);
                    }
                    else return false;
                }

            }
        }
        // verifica quadrados
        for (int quad = 0; quad < 9; quad++) {
            unordered_set<char> visto;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int linha = (quad / 3) * 3 + i;
                    int coluna = (quad % 3) * 3 + j;
                    if (board[linha][coluna] != '.'){
                        if (visto.find(board[linha][coluna]) == visto.end()){
                            visto.insert(board[linha][coluna]);
                        }
                        else return false;
                    }
                }
            }
        }

        return true;
    }
};
