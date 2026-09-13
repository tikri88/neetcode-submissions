class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        //1. Initialise left and right pointer
        int left = 0;
        std::unordered_set<char>charSet;
        for(int right=0; right<s.size();right++)
        {
            /**2.Shrink window from left until cache does not have s[right] present. Lets assume s[right] is presnt in cache may be a third character, it does not make sense to store any character in cache till third character is removed which is causing duplicate. Since this is being checked every s[right], while expanding right it was already made sure that it does not have duplicate till now and it already has accounted for maxLength **/
            while(charSet.contains(s[right]))
            {
                charSet.erase(s[left]);
                left++;
            }
            //3. Now windows is safe from duplicate, store s[right] in cache because there is no other s[right] present in cache
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right-left+1);

        }
    return maxLength;
        
    }
};
