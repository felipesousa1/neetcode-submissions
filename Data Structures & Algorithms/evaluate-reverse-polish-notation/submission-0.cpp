class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>res;
        for (string token : tokens){
            int num;
            if (token == "+"){
                num = res.top();
                res.pop();
                num += res.top();
                res.pop();
            }
            else if (token == "-"){
                num = res.top();
                res.pop();
                num = res.top() - num;
                res.pop();          
            }
            else if (token == "*"){
                num = res.top();
                res.pop();
                num *= res.top();
                res.pop();
            }
            else if (token == "/"){
                num = res.top();
                res.pop();
                num = res.top()/num;
                res.pop();
            }
            else {
                num = stoi(token);
            }
            res.push(num);

        }
        return res.top();
    }
};
