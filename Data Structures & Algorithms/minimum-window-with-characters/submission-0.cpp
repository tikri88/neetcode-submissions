class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> freqT;
        //First count freq of each element in t
        for(auto c : t)
        {
            freqT[c] += 1;
        }
        std::unordered_map<char, int> freqW;
        int have=0, need=freqT.size();
        int minLength = INT_MAX;
        int wLeft = 0;
        int minStart = 0;
        for(int wRight=0; wRight<s.size(); wRight++)
        {
            char ch = s[wRight];
            freqW[ch]++;
            if(freqT.count(ch) && freqW[ch] == freqT[ch])
            {
                have++;
            }
            while(have == need)
            {
                if(wRight-wLeft+1 < minLength)
                {
                    minLength = wRight-wLeft+1;
                    minStart = wLeft;

                }
                char chLeft = s[wLeft];
                freqW[chLeft]--;
                if(freqT.count(chLeft) && freqW[chLeft] < freqT[chLeft])
                {
                    have--;
                }
                wLeft++;
            }

        }
        return minLength == INT_MAX ? "":s.substr(minStart, minLength);
    }
};
