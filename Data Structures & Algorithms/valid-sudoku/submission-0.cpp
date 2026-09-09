class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>st;
        for (int i=0;i<9;i++){
          for (int j=0;j<9;j++){
            if (board[i][j]=='.'){
              continue;
            }
            string row="R"+to_string(i)+board[i][j];
            string col="C"+to_string(j)+board[i][j];
            string box="B"+to_string(i/3)+to_string(j/3)+board[i][j];
            if (st.count(row)|| st.count(col)|| st.count(box)){
              return false;
            }
            st.insert(row);
            st.insert(col);
            st.insert(box);
          }
        }
        return true;
    }
};
