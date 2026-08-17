class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> result;
        //Phase 1: Count freq of each element and store it in hashmap
        std::unordered_map<int, int> counts;
        for(int num : nums)
        {
            counts[num]++;
        }
        // Phase2: Create a min heap for pair<freq, num> so that we can get top K freq elements
        std::priority_queue<std::pair<int, int>> max_heap;
        for(auto & [num, freq] : counts)
        {
            max_heap.push(std::make_pair(freq, num));
        }
        //Phase 3: Store top K elements in actual result
        while(!max_heap.empty() && result.size() < k)
        {
            result.push_back(max_heap.top().second);
            max_heap.pop();
        }
    return result;
    }
};
