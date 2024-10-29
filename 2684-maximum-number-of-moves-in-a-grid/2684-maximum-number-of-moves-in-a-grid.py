class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        dp = [[-1] * col] + [[0] * col for _ in range(row)] + [[-1] * col]
        grid = [[1000001] * col] + grid + [[1000001] * col]
        result = 0
        for i in range(1, col):
            for j in range(1, row + 1):
                flag = False
                for d in [-1, 0, 1]:
                    if dp[j + d][i - 1] != -1 and grid[j][i] > grid[j + d][i - 1]:
                        dp[j][i] = max(dp[j][i], dp[j + d][i - 1] + 1)
                        flag = True
                if not flag:
                    dp[j][i] = -1
                result = max(result, dp[j][i])
        return result
        