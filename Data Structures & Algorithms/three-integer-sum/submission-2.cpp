class Solution {
public:
    vector<vector<int>> findIndexes(vector<int>&numbers, int index, int target)
    {
        int s=index, e=numbers.size()-1;
        std::vector<vector<int>>indexes;
        while(s<e)
        {
            if(target == (numbers[s]+numbers[e]))
            {
                indexes.push_back({numbers[s], numbers[e]});
                s++;
                e--;
            }
            else if(target > numbers[s]+numbers[e])
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        return indexes;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        // Hint- n1+n2+n3 = 0 means n1=-(n2+n3), basically for each element in array find rest two other elements whose sum is -(current element)
        std::sort(nums.begin(), nums.end());
        set<vector<int>>unique_result;
        for(size_t i=0; i<nums.size()-2; i++)
        {
            int target = -nums[i];
            vector<vector<int>> indexes = findIndexes(nums, i+1, target);
            if(indexes.size())
            {
                for(auto vecData : indexes)
                unique_result.insert({nums[i], vecData[0], vecData[1]});
            }

        }
        std::vector<std::vector<int>> final_result(unique_result.begin(), unique_result.end());
        return final_result;

    }
};
