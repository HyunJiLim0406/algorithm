class Solution:
    def merge(self, left: List[int], right: List[int]):
        result = []

        while left and right:
            if left[0] < right[0]:
                result.append(left[0])
                left.pop(0)
            else:
                result.append(right[0])
                right.pop(0)
        
        while left:
            result.append(left.pop(0))
        while right:
            result.append(right.pop(0))
        return result

    def divide(self, nums: List[int]):
        if len(nums) == 1:
            return nums

        idx = (int) (len(nums) / 2)
        left = self.divide(nums[:idx])
        right = self.divide(nums[idx:])
        return self.merge(left, right)

    def sortArray(self, nums: List[int]) -> List[int]:
        return self.divide(nums)
        