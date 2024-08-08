class Solution:
    def minimumPushes(self, word: str) -> int:
        keymap = {}
        for char in word:
            if char in keymap:
                keymap[char] += 1
            else:
                keymap[char] = 1
        keymap = dict(sorted(keymap.items(), key=lambda item: item[1], reverse = True))

        index = result = 0
        for value in keymap.values():
            push = int(index / 8) + 1
            result += push * value
            index += 1
        return result
        