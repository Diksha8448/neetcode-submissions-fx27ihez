class Solution {
public:
    bool isPalindrome(string s) {
        // we will use two pointers 
        //starting point 
        int i=0;
        // last point 
        int size=s.length();
        int j=size-1;

        while(i<j){
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            else{
                i++;
                j--;
            }
              
        }
      return true;
    }
};
