class Solution {
    private int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] dp = new int[m][n];
        int max = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max = Math.max(max, dfs(matrix, i, j, dp));
            }
        }

        return max;
    }

    private int dfs(int[][] matrix, int row, int col, int[][] dp) {
        if (dp[row][col] != 0) {
            return dp[row][col];
        }

        int max = 1;

        for (int[] dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newRow < matrix.length &&
                newCol >= 0 && newCol < matrix[0].length &&
                matrix[newRow][newCol] > matrix[row][col]) {
                max = Math.max(max, 1 + dfs(matrix, newRow, newCol, dp));
            }
        }

        dp[row][col] = max;
        return max;
    }
}