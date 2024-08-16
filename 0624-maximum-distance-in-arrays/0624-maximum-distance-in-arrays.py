import heapq

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        minArr = sorted([[min(array), index] for index, array in enumerate(arrays)])
        maxArr = sorted([[max(array), index] for index, array in enumerate(arrays)], reverse = True)
        
        if minArr[0][1] != maxArr[0][1]:
            return maxArr[0][0] - minArr[0][0]
        else:
            return max(maxArr[1][0] - minArr[0][0], maxArr[0][0] - minArr[1][0])
        