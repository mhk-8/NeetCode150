class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i =0 ; i<n; i++){
            if(tokens[i] == "-" || tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/"){
                int left = s.top(); s.pop();
                int right = s.top(); s.pop();
                if(tokens[i] == "-")s.push(right-left);
                if(tokens[i] == "+")s.push(right+left);
                if(tokens[i] == "*")s.push(right*left);
                if(tokens[i] == "/")s.push(right/left);
            }
            else{
                s.push(stoi(tokens[i]));
            }
            
        }
        return s.top();
    }
};
