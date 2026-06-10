class Solution {
public:
    void helper(int index,vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&ds){
        // when the condition is met push to the ans
        if(target==0){
            ans.push_back(ds);
            return;
        }
        // main iteration start from ind->size-1
        for(int i=index;i<candidates.size();i++){
            // to skip the repeated element
            if(i>index && candidates[i]==candidates[i-1]) continue;
            // continue means move to next interator

            //to check whether the number we are trying to include 
            // is greater than what we actually need 
            // then also we will skip
            if(candidates[i]>target) break; // break because no point moving forward

            ds.push_back(candidates[i]);
            helper(i+1,candidates,target-candidates[i],ans,ds);
            ds.pop_back();
            
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // we will sort since we need in sorted order
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0,candidates,target,ans,ds);
        return ans;
    }
};
