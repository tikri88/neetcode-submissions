class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // If we see numbers carefully, every seq will have a start point(This is to avoid recomputing same seq). For each start point, compute length and update longest
        unordered_set<int>numSet(nums.begin(), nums.end());
        size_t longest = 0;
        for(auto n : nums)
        {
            // Check if this number is start point of sequence
            if(numSet.find(n-1) == numSet.end())
            {
               // Find length of sequence
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
