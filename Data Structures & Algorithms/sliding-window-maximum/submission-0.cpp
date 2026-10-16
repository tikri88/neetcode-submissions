class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;
        std::priority_queue<std::pair<int, int>> pq;
        int left = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            pq.push({nums[right], right});
            int wSize = right-left+1;
            if(wSize == k)
            {
                result.push_back(pq.top().first);
            }
            else if(wSize > k)
            {
                left++;
                while(!pq.empty() && pq.top().second < left)
                {
                    pq.pop();
                }
                result.push_back(pq.top().first);

            }
        }
        return result;
    }
};
