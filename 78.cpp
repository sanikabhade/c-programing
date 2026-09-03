class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums, int index) {
        // Add current subset
        ans.push_back(temp);

        // Try adding each remaining element
        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);

            solve(nums, i + 1);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};