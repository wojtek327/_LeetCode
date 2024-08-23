class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        closest = float('inf')
        for x in nums:
            if abs(x) < abs(closest):
                closest = x
        
        if closest < 0 and abs(closest) in nums:
            return abs(closest)
        return closest