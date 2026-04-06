class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i=0; i<9;i++){
            for(int j=0; j<9; j++){
                char val = board[i][j];
                if(val != '.'){
                    if(
                        !s.insert(string("r")+(char)i+val).second ||
                        !s.insert(string("c")+(char)j+val).second ||
                        !s.insert(string("b")+(char)(i/3) + (char)(j/3) +val).second 
                    ) return false;
                }
            }
        }
        return true;
    }
};
