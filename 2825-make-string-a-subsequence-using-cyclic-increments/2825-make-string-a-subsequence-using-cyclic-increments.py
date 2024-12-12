class Solution:
    def cyclic(self, c: str):
        if c == 'z':
            return 'a'
        return chr(ord(c) + 1)

    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        p1, p2 = 0, 0
        while p1 < len(str1) and p2 < len(str2):
            if str1[p1] == str2[p2] or self.cyclic(str1[p1]) == str2[p2]:
                p1 += 1
                p2 += 1
                if p2 == len(str2):
                    return True
            else:
                p1 += 1
        return False
        