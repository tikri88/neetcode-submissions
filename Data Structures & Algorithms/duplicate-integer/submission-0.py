class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        alreadySeen = set()
        for n in nums:
            if n in alreadySeen:
                return True
            else:
                alreadySeen.add(n)
        return False
        