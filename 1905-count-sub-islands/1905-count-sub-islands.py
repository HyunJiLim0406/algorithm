class Solution:
    def init(self, grid: List[List[int]]):
        candidates = []
        for row in range(len(grid)):
            for col in range(len(grid[row])):
                if grid[row][col] == 1:
                    candidates.append([row, col])
        return candidates

    def bfs(self, row: int, col: int, grid1: List[List[int]], grid2: List[List[int]]):
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        grid2[row][col] = 0
        queue = [[row, col]]
        isValid = True
        while len(queue) > 0:
            row, col = queue.pop(0)
            if grid1[row][col] == 0:
                isValid = False
            for dir in dirs:
                newRow = row + dir[0]
                newCol = col + dir[1]
                if 0 <= newRow < len(grid2) and 0 <= newCol < len(grid2[0]) and grid2[newRow][newCol] == 1:
                    grid2[newRow][newCol] = 0
                    queue.append([newRow, newCol])
        return isValid, grid2

    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        candidates = self.init(grid2)
        result = 0

        while len(candidates) > 0:
            row, col = candidates.pop(0)
            if grid2[row][col] == 0:
                continue
            isValid, grid2 = self.bfs(row, col, grid1, grid2)
            if isValid:
                result += 1
        return result
        