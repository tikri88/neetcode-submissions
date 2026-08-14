class Solution {
public:

    bool isNonAlphaNumeric(char ch)
    {
        return !((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
    }

    bool charEqualsIgnoreCase(char ch1, char ch2)
    {
        return std::tolower(static_cast<unsigned char>(ch1)) == std::tolower(static_cast<unsigned char>(ch2));
    }

    bool isPalindrome(string s) {
        int end = s.length()-1;
        int start = 0;
        while (start < end)
        {
            if(isNonAlphaNumeric(s[start]))
            {
                start += 1;
                continue;
            }
            if (isNonAlphaNumeric(s[end]))
            {
                end -= 1;
                continue;
            }
            if(charEqualsIgnoreCase(s[start], s[end]))
            {
                start += 1;
                end -= 1;
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};
