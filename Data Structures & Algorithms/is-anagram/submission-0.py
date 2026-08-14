class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sLength, tLength = len(s), len(t)
        if sLength != tLength:
            False
        # Either Take Frqquency array of 26 or use hashmap(dict)
        freq = [0]*26
        for ch in s:
            freq[ord(ch)- ord('a')] += 1
        for ch in t:
            freq[ord(ch)-ord('a')] -= 1
        for value in freq:
            if value != 0:
                return False
        return True 
        
        