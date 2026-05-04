class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //we are using sorting method
        // we will initialise map
        unordered_map<string,vector<string>>mp;

        //we will iterate through vector string
        for(string s:strs){
            string key=s;// every string let's say is key
            // we will sort every key 
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        // for the result 
        vector<vector<string>>result;

        //we will iterate through map
        for(auto &it:mp){
            result.push_back(it.second);
        }


       return result;

       // but its time complexity will be big because of sorting
       // Time Complexity O(N * K log K)
       // Space complexity O(NK)

    }
};
