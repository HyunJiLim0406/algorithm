class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = [' '] * (len(s) + len(spaces))
        sIdx, spaceIdx, margin = 0, 0, 0
        for index, char in enumerate(result):
            if spaceIdx < len(spaces) and index == spaces[spaceIdx] + margin:
                margin += 1
                spaceIdx += 1
            else:
                result[index] = s[sIdx]
                sIdx += 1
        return ''.join(result)
        