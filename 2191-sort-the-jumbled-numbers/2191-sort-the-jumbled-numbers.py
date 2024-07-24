class Solution:
    def mappingNumber(self, mapping: List[int], num: int):
        numStr = str(num)
        result = ''
        
        for c in numStr:
            result += str(mapping[int(c)])
        return int(result)

    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            nums[i] = [nums[i], self.mappingNumber(mapping, nums[i])]

        nums.sort(key = lambda x:x[1])
        return [sub[0] for sub in nums]
        