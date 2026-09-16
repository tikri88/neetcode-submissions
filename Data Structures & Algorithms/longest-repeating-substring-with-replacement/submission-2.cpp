class Solution {
public:
    int findMaxFreq(int arr[26]) {
        int maxValue = 0;
        for(int i = 0; i < 26; i++) {
            maxValue = std::max<int>(maxValue, arr[i]);
        }
        return maxValue;
    }

    int characterReplacement(string s, int k) {
        int maxL = 0;
        int l = 0;
        int freq[26] = {0};

        for(int r = 0; r < s.size(); r++) {
            // 1. Expand window by adding the right character
            freq[s[r] - 'A'] += 1;

            // 2. Shrink window from left until it becomes valid
            while ((r - l + 1) - findMaxFreq(freq) > k) {
                freq[s[l] - 'A'] -= 1;
                l++;
            }

            // 3. Now the window is guaranteed valid, track the max length
            maxL = std::max(maxL, r - l + 1);
        }
        return maxL;
    }
};
