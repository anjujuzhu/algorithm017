class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int rowSize = matrix.size(), colSize = matrix[0].size();
        if (colSize == 0 || rowSize == 0) return false;
        int row = 0, col = colSize - 1;
        while (row < rowSize && col >= 0) {
            if (matrix[row][col] >target) {
                col -= 1;
            } else if (matrix[row][col]  < target) {
                row += 1;
            } else return true;
        }
        return false;
    }
};