class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result;
        for(int i=0; i<=n ;i++)
        {
            int pos = 1;
            int setBits = 0;
            for(int j=0; j<32; j++)
            {
                if(i & pos)
                    setBits++;
                pos <<= 1;
            }
            result.push_back(setBits);
        }
        return result;
    }
};
