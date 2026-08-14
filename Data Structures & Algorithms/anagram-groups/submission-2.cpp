class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(const string& str : strs)
        {
            char count[26] = {0};
            for(int i = 0; i< str.size(); i++)
            {
                count[str[i] - 'a'] += 1;
            }
            string key = "";
            for(int i = 0; i<26; i++)
            {
                key += std::to_string(count[i]) + '#';
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto &pair : mp)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
