class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxLeft =height[l], maxRight = height[r];
        int trapWater = 0;
        while(l <= r)
        {
            int currWater = 0;
            if(maxLeft <= maxRight)
            {
                
                currWater = maxLeft - height[l];
                maxLeft = std::max(maxLeft, height[l]);
                l++;
            }
            else
            {
                currWater = maxRight - height[r];

                maxRight = std::max(maxRight, height[r]);
                r--;

            }
            if(currWater > 0)
            {
                trapWater += currWater;
            }

        }
        return trapWater;
    }
};
