class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> block(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char x = board[i][j];
                if (x == '.') continue;

                int b = (i/3)*3 + j/3;

                if (!row[i].insert(x).second ||
                    !col[j].insert(x).second ||
                    !block[b].insert(x).second) return false;
            }
        }

        return true;
    }
};
