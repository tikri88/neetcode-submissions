class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result = "";
        for(const auto& str:strs)
        {
            result += std::to_string(str.size()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string>decodedString;
        size_t i = 0;
        while(i < s.size())
        {
            int j= i;
            while(s[j] != '#')
            {
                j++;
            }
            auto strSize = std::stoi(s.substr(i, j));
            auto subString = s.substr(j+1, strSize);
            decodedString.push_back(subString);
            i = j+1+strSize;

        }
        return decodedString;
    }
};
