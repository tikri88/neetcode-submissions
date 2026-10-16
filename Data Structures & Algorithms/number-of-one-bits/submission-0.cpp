class Solution {
public:
    int hammingWeight(uint32_t n) {
        int position = 1;
        int totalBits = 0;
        for(int i=0;i<32; i++)
        {
            if(n & (position))
                totalBits++;
            position <<= 1;

        }
        return totalBits;
    }
};
