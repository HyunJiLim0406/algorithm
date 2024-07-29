class Solution:
    def numTeams(self, rating: List[int]) -> int:
        result = 0

        for middle in range(1, len(rating) - 1):
            leftAsc = leftDesc = rightAsc = rightDesc = 0

            for i in range(len(rating)):
                if i < middle and rating[i] < rating[middle]:
                    leftAsc += 1
                elif middle < i and rating[middle] < rating[i]:
                    rightAsc += 1
                    
            leftDesc = middle - leftAsc
            rightDesc = len(rating) - middle - rightAsc - 1
            
            result += (leftAsc * rightAsc + leftDesc * rightDesc)

        return result
        