import heapq

class Solution:
    def smaller(self, candidate: List[int], answer: List[int]):
        if candidate[1] - candidate[0] < answer[1] - answer[0]:
            return candidate
        if candidate[1] - candidate[0] == answer[1] - answer[0]:
            return candidate if candidate[0] < answer[0] else answer
        return answer

    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        heap, maxNum = [], -100001
        result = [-100001, 100001]

        for index, num in enumerate(nums):
            heapq.heappush(heap, [num[0], index, 0])
            maxNum = max(maxNum, num[0])

        while True:
            minNum, numIdx, idx = heapq.heappop(heap)
            if maxNum - minNum < result[1] - result[0]:
                result = self.smaller([minNum, maxNum], result)
            if len(nums[numIdx]) == idx + 1:
                break
            nextNum = nums[numIdx][idx + 1]
            heapq.heappush(heap, [nextNum, numIdx, idx + 1])
            maxNum = max(maxNum, nextNum)
        return result
        