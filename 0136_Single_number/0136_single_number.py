class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        element = 0

        for x in nums:
            element ^= x

        return element