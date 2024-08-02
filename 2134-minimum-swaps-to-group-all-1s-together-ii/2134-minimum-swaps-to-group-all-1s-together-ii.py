class Solution:
    def countOnes(self, nums: List[int]):
        count = 0
        for num in nums:
            if num == 1:
                count += 1
        return count

    def initWindow(self, size: int, nums: List[int]):
        window = []
        countZero = 0

        for i in range(size):
            window.append(nums[i])
            if nums[i] == 0:
                countZero += 1
        return window, countZero

    def minSwaps(self, nums: List[int]) -> int:
        windowSize = index = self.countOnes(nums)
        (window, minCount) = self.initWindow(windowSize, nums)
        currentCount = minCount

        while index < len(nums):
            window.append(nums[index])
            if nums[index] == 0:
                currentCount += 1
            if window.pop(0) == 0:
                currentCount -= 1
            
            if currentCount < minCount:
                minCount = currentCount
            
            index = (index + 1) % len(nums)
            if index == windowSize:
                break
        
        return minCount
