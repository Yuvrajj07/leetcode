class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int store = 0;
        bool chk = false;

        for (const auto& interval : intervals) {
            int x = interval[0];
            int y = interval[1];

            if (!chk) {
                if (ans.empty() || ans.back()[1] < x) {
                    ans.push_back({x, y});
                } else {
                    store = ans.back()[0];
                    ans.back()[1] = max(ans.back()[1], y);
                    chk = true;
                }
            } 
            else {
                if (ans.back()[1] < x) {
                    ans.push_back({x, y});
                    chk = false;
                } else {
                    ans.back()[1] = max(ans.back()[1], y);
                }
            }
        }

        return ans;
    }
};
