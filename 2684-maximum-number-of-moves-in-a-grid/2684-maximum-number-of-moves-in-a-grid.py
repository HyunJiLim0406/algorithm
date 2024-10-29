class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        array = [[0] * len(grid[0]) for _ in range(len(grid))]
        result = 0
        for i in range(1, len(grid[0])):
            for j in range(len(grid)):
                flag = False
                if j > 0 and array[j - 1][i - 1] != -1 and grid[j][i] > grid[j - 1][i - 1]:
                    array[j][i] = max(array[j][i], array[j - 1][i - 1] + 1)
                    flag = True
                if array[j][i - 1] != -1 and grid[j][i] > grid[j][i - 1]:
                    array[j][i] = max(array[j][i], array[j][i - 1] + 1)
                    flag = True
                if j + 1 < len(grid) and array[j + 1][i - 1] != -1 and grid[j][i] > grid[j + 1][i - 1]:
                    array[j][i] = max(array[j][i], array[j + 1][i - 1] + 1)
                    flag = True
                if not flag:
                    array[j][i] = -1
                result = max(result, array[j][i])
        return result
        