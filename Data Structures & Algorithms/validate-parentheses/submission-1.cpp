class Solution {
public:
    bool isValid(string s) {
        vector<char> open = {'(', '{', '['};
        vector<char> close = {')', '}', ']'};
        stack<char> pilha;

        for(char c : s){
            if (find(open.begin(), open.end(), c) != open.end()){
                pilha.push(c); 
                continue;
            } 
            for (int i = 0; i < 3; i++){
                if (c == close[i]){
                    if (pilha.empty() || pilha.top() != open[i]) return false;
                    else {
                        pilha.pop();
                        break;
                    }
                }
            }
        }
        return pilha.empty();
    }
};
