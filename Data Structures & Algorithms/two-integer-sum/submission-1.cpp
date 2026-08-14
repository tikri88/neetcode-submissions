class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> checkPresent;
        vector<int> result;
        for (size_t i= 0; i<nums.size(); i++)
        {
            auto itr = checkPresent.find(target-nums[i]);
            if (itr != checkPresent.end())
            {
                auto itr_to_element = find(nums.begin(), nums.end(), *itr);
                std::size_t index = std::distance(std::begin(nums), itr_to_element);
                result.push_back(index);
                result.push_back(i);
                break;
            }
            else
            {
                checkPresent.insert(nums[i]);
            }
        }
        return result;
        
    }
};
