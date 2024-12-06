class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        bannedSet = {num for num in banned if num <= n}
        result, resultSum = 0, 0
        for i in range(1, n + 1):
            if i not in bannedSet:
                if resultSum + i <= maxSum:
                    result += 1
                    resultSum += i
                else:
                    break
        return result
        