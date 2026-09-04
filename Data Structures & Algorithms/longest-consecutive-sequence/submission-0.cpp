class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>numSet(nums.begin(), nums.end());
        size_t longest = 0;
        for(auto n : nums)
        {
            if(numSet.find(n-1) == numSet.end())
            {
                size_t length = 1;
                while(numSet.find(n+length) != numSet.end())
                {
                    length++;
                }
                longest = std::max(longest, length);
            }
        }
        return longest;
    }
};
