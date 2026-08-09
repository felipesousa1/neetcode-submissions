class Solution {
private:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int index){
        if (index == word.size()) return true;
        
        if (i<0 || i>board.size()-1 || 
            j<0 || j>board[0].size()-1 || 
            board[i][j] != word[index]) return false;
        
        char temp = board[i][j];
        board[i][j] = '!';

        bool res = backtrack(board, word, i-1, j, index+1) ||
                   backtrack(board, word, i+1, j, index+1) ||
                   backtrack(board, word, i, j-1, index+1) ||
                   backtrack(board, word, i, j+1, index+1);
        
        board[i][j] = temp;

        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i<row; i++){
            for (int j = 0; j<col; j++){
                if (backtrack(board, word, i, j, 0)) return true;
            }
        }
        
        return false;
    }
};
