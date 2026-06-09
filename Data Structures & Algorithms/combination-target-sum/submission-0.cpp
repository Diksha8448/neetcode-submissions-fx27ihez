class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& nums,
                   int target,
                   int index) {

        // Found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Invalid path
        if (target < 0 || index >= nums.size())
            return;

        // Choice 1: Take current number
        current.push_back(nums[index]);

        backtrack(nums,
                  target - nums[index],
                  index);      // same index

        current.pop_back();

        // Choice 2: Skip current number
        backtrack(nums,
                  target,
                  index + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0);
        return result;
    }
};
