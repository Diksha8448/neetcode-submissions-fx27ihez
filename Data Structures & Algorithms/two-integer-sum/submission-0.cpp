class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> result;
        
        for (int i=0;i<n;i++){
            int other=target-nums[i];
            if(result.find(other)!=result.end()){
                return{result[other],i};
            }
            result.insert({nums[i], i});
        }

        return {};

        
    }
};
