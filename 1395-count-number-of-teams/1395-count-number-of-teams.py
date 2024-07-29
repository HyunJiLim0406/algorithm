class Solution:
    def numTeams(self, rating: List[int]) -> int:
        result = 0

        for i in range(1, len(rating) - 1):
            leftAsc = leftDesc = rightAsc = rightDesc = 0

            for j in range(i):
                if rating[j] < rating[i]:
                    leftAsc += 1
            leftDesc = i - leftAsc

            for j in range(i + 1, len(rating)):
                if rating[i] < rating[j]:
                    rightAsc += 1
            rightDesc = len(rating) - i - rightAsc - 1
            
            result += (leftAsc * rightAsc + leftDesc * rightDesc)

        return result
        