class Solution {
public:
    void backtrack(vector<int>& nums,
                   vector<vector<int>>& ans,
                   vector<int>& ds,
                   int index) {

        ans.push_back(ds);

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1])
                continue;

            ds.push_back(nums[i]);

            backtrack(nums, ans, ds, i + 1);

            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        backtrack(nums, ans, ds, 0);

        return ans;
    }
};
