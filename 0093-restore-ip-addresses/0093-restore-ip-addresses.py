class Solution:
    def __init__(self):
        self.result = []

    def isValid(self, addresses: List[str]):
        for address in addresses:
            if (len(address) > 1 and address[0] == '0') or len(address) > 3 or int(address) > 255:
                return False
        return True

    def backtracking(self, addresses: List[str]):
        if len(addresses) == 4:
            if self.isValid(addresses):
                self.result.append('.'.join(addresses))
            return
        lastAddress = addresses[-1]
        for i in range(1, len(lastAddress)):
            newAddress = addresses[:-1] + [lastAddress[:i], lastAddress[i:]]
            self.backtracking(newAddress)


    def restoreIpAddresses(self, s: str) -> List[str]:
        if len(s) < 4 or len(s) > 12:
            return []
        self.backtracking([s])
        return self.result
        