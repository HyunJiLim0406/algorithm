import heapq, math

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        maxHeap = [-num for num in nums]
        heapq.heapify(maxHeap)
        score = 0

        while k:
            num = -heapq.heappop(maxHeap)
            score += num
            heapq.heappush(maxHeap, -math.ceil(num / 3))
            k -= 1
        return score
        