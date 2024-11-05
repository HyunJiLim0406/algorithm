class Solution:
    def compressedString(self, word: str) -> str:
        result, cnt, cur = '', 1, word[0]
        for w in word[1:]:
            if w == cur and cnt < 9:
                cnt += 1
            else:
                result += (str(cnt) + cur)
                cnt, cur = 1, w
        result += (str(cnt) + cur)
        return result
        