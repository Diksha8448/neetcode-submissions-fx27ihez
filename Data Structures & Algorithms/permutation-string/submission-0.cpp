class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // we need two vector to keep count of the letters

        vector<int>freqs1(26,0);
        vector<int>window(26,0);
        
        // this is for string first 
        for(int i=0;i<s1.size();i++){
            freqs1[s1[i]-'a']++;
        }
         // for window
        int left=0;
        int right=0;

        for(int right=0;right<s2.size();right++){
           // we will again fill the window vector
           window[s2[right]-'a']++;

           //vahi window ka bhang bhosda
           if(right-left+1>s1.size()){
             window[s2[left]-'a']--;
             left++;
           }
           
           // compare the vectors
           if(freqs1==window){
            return true;
           }
        }

        return false;

    }
};
