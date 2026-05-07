class Solution {
public:
    int characterReplacement(string s, int k) {
        // a vector for all character with count as 0
       vector<int> freq(26, 0);

    int left = 0;
    int maxFreq = 0;
    int maxLen = 0;

    for (int right = 0; right < s.size(); right++) {

        // increase frequency
        freq[s[right] - 'A']++;

        // track highest frequency character
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // current window size
        int windowSize = right - left + 1;

        // invalid window
        while (windowSize - maxFreq > k) {

            freq[s[left] - 'A']--;
            left++;

            windowSize = right - left + 1;
        }

        maxLen = max(maxLen, windowSize);
    }

    return maxLen;

        
    }
};
