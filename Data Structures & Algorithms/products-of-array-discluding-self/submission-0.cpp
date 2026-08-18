class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tpWithUnknow = 1;
        int tpWithoutZero = 1;
        int total_zeros = 0;
        vector<int> result(nums.size(), 0);
        for(int n : nums)
        {
            if(n == 0)
            {
                total_zeros += 1;
            }
        }
        
        for(const int num : nums)
        {
            if(num != 0)
            {
                tpWithoutZero *= num;
            }
            tpWithUnknow *= num;
        }
        if (total_zeros > 1)
        {
            return result;
        }
        else{
            for(int i = 0;  i<nums.size(); i++)
            {
                if(nums[i] == 0)
                {
                    result[i] = tpWithoutZero;
                }
                else
                {
                    result[i] = tpWithUnknow/nums[i];
                }
            }
        }
    return result;
    }
};
