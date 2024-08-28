class Solution:
    def init(self, grid: List[List[int]]):
        candidates = []
        for row in range(len(grid)):
            for col in range(len(grid[row])):
                if grid[row][col] == 1:
                    candidates.append([row, col])
        return candidates
    
    def isValidPos(self, row, col, rowLen, colLen):
        return 0 <= row < rowLen and 0 <= col < colLen

    def bfs(self, grid1: List[List[int]], grid2: List[List[int]]):
        result = 0
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        candidates = self.init(grid2)

        while len(candidates) > 0:
            row, col = candidates.pop(0)
            if grid2[row][col] == 0:
                continue

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
                    if self.isValidPos(newRow, newCol, len(grid2), len(grid2[0])) and grid2[newRow][newCol] == 1:
                        grid2[newRow][newCol] = 0
                        queue.append([newRow, newCol])
            if isValid:
                result += 1
        return result

    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        return self.bfs(grid1, grid2)
        