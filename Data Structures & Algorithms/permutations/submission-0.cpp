class Solution {
public:
    void backtrack(vector<int>&nums,vector<vector<int>>&ans,vector<int>ds,vector<bool> used){
        // base case
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            ds.push_back(nums[i]);
            used[i]=true;
            backtrack(nums,ans,ds,used);
            ds.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<bool> used(nums.size(), false);
        backtrack(nums,ans,ds,used);
        return ans;
    }
};
