class Solution:
    def convertToMinute(self, timePoint: str):
        hour, minute = timePoint.split(':')
        return int(hour) * 60 + int(minute)

    def findMinDifference(self, timePoints: List[str]) -> int:
        minutePoints = sorted(list(map(self.convertToMinute, timePoints)))
        result = 1440
        for index, point in enumerate(minutePoints):
            nextIndex = (index + 1) % len(minutePoints)
            timeDiff = abs(point - minutePoints[nextIndex])
            result = min(result, timeDiff, 1440 - timeDiff)

        return result
        