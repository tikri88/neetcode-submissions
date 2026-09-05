class Solution {
public:
    int trap(vector<int>& height) {
        /** Two approach to solve this problem. Using Prefix sum of leftMax and rightMax and take min of it.
        second approach is to use two pointer solution to avoid storage
        **/
        vector<int>leftMaxArray(height.size(), 0);
        vector<int>rightMaxArray(height.size(), 0);
        int leftMax = 0, rightMax=0;
        //Prepare LeftMaxArray
        for(int i=0; i<height.size(); i++)
        {
            leftMaxArray[i] = leftMax;
            leftMax = std::max(leftMax, height[i]);
        }
        //Prepare rightMaxArray
        for(int j=height.size()-1; j>=0; j--)
        {
            rightMaxArray[j] = rightMax;
            rightMax = std::max(rightMax, height[j]);
        }
        for(auto val : rightMaxArray)
        {
            std::cout<<val <<" ";
        }
        int totalTrapW = 0;
        for(int i=0; i<height.size(); i++)
        {
            int min = std::min(leftMaxArray[i], rightMaxArray[i]);

            if(min-height[i] > 0)
            {
                totalTrapW += min-height[i];
            }
        }
        return totalTrapW;
    }
};
