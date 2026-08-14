class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        for(const std::string& str : strs)
        {
            //Anagram strings will result in same key after sorting.
            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(str);
        }
        // Get grouped anagram from hashmap to fine 2d result vector
        for(auto& pair : anagramMap)
        {
            result.push_back(std::move(pair.second));
        }
        return result;        
    }
};
