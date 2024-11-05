class Solution:
    def minChanges(self, s: str) -> int:
        result = 0
        for a, b in zip(s[::2], s[1::2]):
            if a != b:
                result += 1
        return result