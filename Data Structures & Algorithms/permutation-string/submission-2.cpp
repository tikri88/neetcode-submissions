class Solution {
public:
    bool compareFreq(const unordered_map<char, int>&freqS1, const unordered_map<char, int>&freqS2)
    {
        if(freqS1.size() != freqS2.size())
            return false;
        for(auto item : freqS2)
        {
            auto itr = freqS1.find(item.first);
            if(itr == freqS1.end() || itr->second != item.second)
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {

        std::unordered_map<char, int>freqS1;
        std::unordered_map<char, int>freqS2;
        int l=0;
        for(auto ch:s1)
        {
            freqS1[ch] += 1;
        }
        for(int r=0;r<s2.size(); r++)
        {
            freqS2[s2[r]] += 1;
            //Check if substring is of same size as s1
            if(r-l+1 == s1.size())
            {
                //Compare freq of each char from both s1 and substring.
                if(compareFreq(freqS1,  freqS2))
                {
                    return true;
                }
                freqS2[s2[l]] -= 1;
                if(freqS2[s2[l]] == 0)
                {
                    freqS2.erase(s2[l]);
                }
                l++;
            }
        }
        return false;
        
    }
};
