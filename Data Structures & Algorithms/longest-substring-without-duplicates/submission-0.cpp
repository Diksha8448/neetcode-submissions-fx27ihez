class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // we are using set to check the repetition
        unordered_set<char>st;
        int left=0;
        int maxLen=0;

        for(int right=0;right<s.size();right++){
            // check if it already exists
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};
