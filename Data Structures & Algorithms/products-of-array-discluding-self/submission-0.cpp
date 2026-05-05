class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //basically concept is product of left and product of right

        // we will need answer vector
           int n=nums.size();
        vector<int>ans(n,1);
     

        // we will start with prefix
        int prefix=1;
        for(int i=0;i<n;i++){
            ans[i]=prefix;
            prefix*=nums[i];
        }

        //suffix
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=suffix;
            suffix*=nums[i];
        }

        return ans;

    }
};