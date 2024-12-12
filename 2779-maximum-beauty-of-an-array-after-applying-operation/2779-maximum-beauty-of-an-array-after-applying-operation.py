class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        left, right, result = 0, 1, 0
        while left <= right and right < len(nums):
            if nums[right] - nums[left] <= 2 * k:
                result = max(result, right - left)
                right += 1
            else:
                left += 1
        return result + 1
        