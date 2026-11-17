class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t = 0, b = matrix.size() - 1;
        int l = 0, r = matrix[0].size() - 1;

        int row = 0;
        while (t <= b) {
            int m = t + (b-t) / 2;
            if (matrix[m][0] == target) return true;
            else if (matrix[m][0] < target) t = m + 1;
            else b = m - 1;
            row = b;
            if (row < 0) return false;
        }

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (matrix[row][m] == target) return true;
            else if (matrix[row][m] < target) l = m + 1;
            else r = m - 1;
        }

        return false;
    }
};
