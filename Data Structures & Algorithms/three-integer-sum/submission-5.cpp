class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // this is to be done by two pointer method 
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;

        // we need to fix i and move j and k 
        // for that we need loop 
        // n is the size , n-1 is k so it will move till n-2 to avoid duplicate

        for(int i=0;i<n-2;i++){

            //skip duplicates for i
            if(i>0 && nums[i]==nums[i-1])
             continue;

            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    vector<int>ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    ans.push_back(nums[k]);
                    result.push_back(ans);
                    j++;
                    k--;

                    //skip duplicates for j
                    while(j<k && nums[j]==nums[j-1])
                       j++;

                    //skip duplicates for k
                    while(j<k && nums[k]==nums[k+1])
                        k--;
                }
                else if (sum<0){
                    j++;
                }
                else{
                    k--;
                }
            }

        }
        
        return result;
    }
};
