class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals based on the starting times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int storeStart = 0;
        bool hasOverlap = false;

        for (const auto& interval : intervals) {
            int x = interval[0];
            int y = interval[1];

            if (!hasOverlap) {
                if (ans.empty() || ans.back()[1] < x) {
                    ans.push_back({x, y});
                } else {
                    storeStart = ans.back()[0];
                    ans.back()[1] = max(ans.back()[1], y);
                    hasOverlap = true;
                }
            } else {
                if (ans.back()[1] < x) {
                    ans.push_back({x, y});
                    hasOverlap = false;
                } else {
                    ans.back()[1] = max(ans.back()[1], y);
                }
            }
        }

        return ans;
    }
};
