class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>result(temperatures.size(), 0);
        stack<pair<int,int>>nextGreater;
        nextGreater.push({temperatures[0], 0});

        for(int i=1; i<temperatures.size(); i++)
        {

            if(temperatures[i] <= nextGreater.top().first)
            {
                nextGreater.push({temperatures[i], i});
            }
            else
            {
                int j = nextGreater.size();
                while(j > 0 && temperatures[i] > nextGreater.top().first)
                {
                    int index = nextGreater.top().second;
                    result[index] = i-index;
                    nextGreater.pop();
                    j--;
                }
                nextGreater.push({temperatures[i], i});
            }
        }
        return result;
    }
};
