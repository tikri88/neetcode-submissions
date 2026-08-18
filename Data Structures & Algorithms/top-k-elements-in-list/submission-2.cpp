class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Use Min Heap approach which will result in O(n*logK) complexity
        std::unordered_map<int, int>counts;
        std::vector<int>result;
        for(auto n : nums)
        {
            counts[n]++;
        }
        std::priority_queue<std::pair<int, int>, std::vector<pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        for(auto& [num, freq] : counts)
        {
            minHeap.push({freq, num});
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        while(!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
