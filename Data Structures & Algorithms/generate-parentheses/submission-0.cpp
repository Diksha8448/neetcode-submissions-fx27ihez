class Solution {
public:
    void backtrack(int open,int close,int n,string str,vector<string>&ans){
        //base case
        //when count of str length ==2*n because of open+close bracket
        if(str.length()==2*n){
            ans.push_back(str);
            return;
        }

        // add "("
        if(open<n){
            backtrack(open+1,close,n,str+"(",ans);

        }

        // add ")"
        if(close<open){
            backtrack(open,close+1,n,str+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;

        backtrack(0,0,n,"",ans);

        return ans;
    }
};
