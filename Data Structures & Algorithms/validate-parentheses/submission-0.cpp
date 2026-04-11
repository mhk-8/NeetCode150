class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(char c: s){
            if(c == '(' || c == '{' || c == '['){
                brackets.push(c);
            }
            else{
                if(brackets.empty()){
                    return false;
                }
                char prev = brackets.top();
                brackets.pop();
                if( c == ')' && prev != '(') return false;
                if( c == ']' && prev != '[') return false;
                if( c == '}' && prev != '{') return false;
            }
        }

        return brackets.empty();
    }
};
