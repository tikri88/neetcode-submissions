class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> output(n, 1);
        
        // Step 1: Compute prefix products (left to right)
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            output[i] = prefix;
            prefix *= nums[i];
        }
        
        // Step 2: Compute suffix products on the fly (right to left)
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            output[i] *= suffix;
            suffix *= nums[i];
        }
        
        return output;
    }
};
