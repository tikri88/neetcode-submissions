class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step1: Count frquency of each element. We can't use just an array to do this because -ve elements will result into crash. Better use hashmap to count
        // Step2: Create a bucket where similar frequncy elements goes into same bicket. Meaning, Bucket index = frequency of each element. Since maximum frequcy can go upto N so bucket size should be N+1 to accomdate indexing from 0 to N.
        // Get K values from bucket. Iterate it from backwords so that we get top K elements by frequency.

        std::unordered_map<int, int> freqCountMp;
        int n = nums.size();
        //Step 1: Count frquency of each element
        for(int num : nums)
        {
            freqCountMp[num] += 1;
        }
        //Step 2: Create bucket and store elements in respective bucket.
        vector<vector<int>> buckets(n+1);
        for(const auto& pair : freqCountMp)
        {
            buckets[pair.second].push_back(pair.first);
        }
        // Step 3: Get top K elements with high frequency
        vector<int> result;
        for(size_t i = n; i >= 0 && result.size()<k; i--)
        {
            for(int ele : buckets[i])
            {
                if(result.size() == k)
                    return result;
                result.push_back(ele);
            }
        }
        return result;
        
    }
};
