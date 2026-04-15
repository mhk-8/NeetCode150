class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (matrix.empty() || matrix[0].empty()) return false;
        int left = 0, right = (m * n) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midV = matrix[mid / n][mid % n];
            if (midV == target) {
                return true;
            } else if (midV < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
