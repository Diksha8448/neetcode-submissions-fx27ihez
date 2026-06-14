class Solution {
public:
    // we will map the num to the string
    vector<string> phone = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void backtrack(string digits,int index,string current, vector<string>&ans){
        if(index==digits.size()){
            ans.push_back(current);    
            return;    
        }
        string letters = phone[digits[index] - '0'];

        for(char ch : letters){

            current.push_back(ch);

            backtrack(digits,
                      index + 1,
                      current,
                      ans);

            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        // we will store the answer
        vector<string> ans;

        if(digits.empty())
            return ans;
   
        // we will store the new string 
        string current;

        backtrack(digits,0,current,ans);

        return ans;
    }
};
