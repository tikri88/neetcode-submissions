class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::multimap<int, int> index_track;
        set<int> checkExist;
        vector<int>result;
        for(int i=0; i<nums.size(); i++)
        {
            index_track.insert({nums[i], i});
        }
        for(size_t i=0; i<nums.size(); i++)
        {
            auto itr = checkExist.find(target-nums[i]);
            if (itr != checkExist.end())
            {
                auto iter = index_track.lower_bound(*itr);
                if (iter != index_track.end())
                {
                    result.push_back(iter->second);
                    result.push_back(i);
                    break;
                }
                else
                {
                    return {-1,-1};
                }
            }
            else
            {
                checkExist.insert(nums[i]);
            }
        }
        return result;
        
    }
};
