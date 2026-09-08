class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Sort intervals based on starting value
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (auto interval : intervals) {
            
            // If ans is empty OR no overlap
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            }
            else {
                // Overlapping intervals → merge them
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};