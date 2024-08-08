class Solution:
    def validPos(self, rows: int, cols: int, rPos: int, cPos: int):
        return 0 <= rPos < rows and 0<= cPos < cols

    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        board = [[False for _ in range(cols)] for _ in range(rows)]

        count = dirIdx = 0
        result = []
        rPos = rStart
        cPos = cStart
        while(count < rows * cols):
            if self.validPos(rows, cols, rPos, cPos):
                board[rPos][cPos] = True
                result.append([rPos, cPos])
                count += 1
            rPos = rPos + dir[dirIdx][0]
            cPos = cPos + dir[dirIdx][1]

            nextDirIdx = (dirIdx + 1) % 4
            rNextPos = rPos + dir[nextDirIdx][0]
            cNextPos = cPos + dir[nextDirIdx][1]
            if not self.validPos(rows, cols, rNextPos, cNextPos) or board[rNextPos][cNextPos] == False:
                dirIdx = nextDirIdx
        return result

        