class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //Brute force approach
        string tmp = s1;
        std::sort(tmp.begin(), tmp.end());
        for(int i=0;i<s2.size(); i++)
        {
            std::string subStr(1, s2[i]);
            if(tmp == subStr)
            {
                return true;
            }
            for(int j=i+1; j<s2.size(); j++)
            {
                subStr += s2[j];
                if(subStr.size() == s1.size())
                {
                    std::sort(subStr.begin(), subStr.end());
                    if(tmp == subStr)
                    {
                        return true;
                    }
                    else
                    {
                        break;
                    }

                }

            }
        }
        return false;
        
    }
};
