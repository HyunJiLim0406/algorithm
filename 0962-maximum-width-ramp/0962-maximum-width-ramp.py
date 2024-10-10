class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        result = 0
        stack = []

        for index, num in enumerate(nums):
            top = stack[-1][1] if stack else 50001
            if top > num:
                stack.append((index, num))
                continue
            for i, n in stack:
                if n <= num:
                    result = max(result, index - i)
                    break
        return result
        