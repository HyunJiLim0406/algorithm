class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        dp = [[0] * (len(matrix[0]) + 2) for _ in range(len(matrix) + 2)]

        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 1:
                    dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j], dp[i][j + 1]) + 1
        
        return sum(sum(row) for row in dp)
        