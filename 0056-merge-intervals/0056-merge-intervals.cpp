// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& v) {
//         sort(v.begin(),v.end());
//      vector<vector<int>>ans;
//         int store=0;
//         bool chk=0;
//         for(auto it:v){
//             int x= it[0];
//             int y= it[1];
//             int z= ++it[0];
//             if(!chk){
//             if (y<z){
//                 ans.push_back({x,y});
//             }
//             else{
//                 store=x;
//                 chk=true;
//             }
//         }
//             if (chk){
//                 if (y<z){
//                     ans.push_back({x,store})
//                 }
//             }
            
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals based on the starting times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (const auto& interval : intervals) {
            vector<int>& lastInterval = ans.back();
            if (lastInterval[1] >= interval[0]) {
                lastInterval[1] = max(lastInterval[1], interval[1]);
            } 
            else {
                ans.push_back(interval);
            }
        }

        return ans;
    }
};
