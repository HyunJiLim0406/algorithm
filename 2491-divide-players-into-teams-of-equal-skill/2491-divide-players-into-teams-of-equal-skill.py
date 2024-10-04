class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        left, right = 0, len(skill) - 1
        target = skill[left] + skill[right]
        result = 0

        while left < right:
            l, r = skill[left], skill[right]
            if l + r != target:
                return -1
            result += l * r
            left += 1
            right -= 1
        return result
        