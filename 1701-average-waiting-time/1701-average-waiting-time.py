class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        current_time = customers[0][0]
        waiting_time = 0.0
        for i, j in customers:
            waiting_time += max(current_time - i, 0) + j
            current_time = max(current_time, i) + j
        return waiting_time / len(customers)

        