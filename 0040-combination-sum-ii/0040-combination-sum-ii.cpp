class Solution {
public:
//     void solve (vector<int>&v1,set<vector<int>>&ans,vector<int>&temp,int curr_sum,int idx,int n){
//         if (curr_sum>=n){
//             if (curr_sum==n){
//                 ans.insert(temp);
//             }
//             return ;
//         }
//         for (int i =idx;i<v1.size();i++){
//             temp.push_back(v1[i]);
//             solve (v1,ans,temp,curr_sum+v1[i],i+1,n);
//             temp.pop_back();
//         }
//     }

void solve(vector<int>& v1,
           vector<vector<int>>& ans,
           vector<int>& temp,
           int curr_sum,
           int idx,
           int n) {

    if (curr_sum == n) {
        ans.push_back(temp);
        return;
    }

    if (curr_sum > n) return;

    for (int i = idx; i < v1.size(); i++) {

        // 🔑 skip duplicates at same recursion level
        if (i > idx && v1[i] == v1[i - 1])
            continue;

        temp.push_back(v1[i]);
        solve(v1, ans, temp, curr_sum + v1[i], i + 1, n);
        temp.pop_back();
    }
}

    vector<vector<int>> combinationSum2(vector<int>&v1, int target) {
        sort(v1.begin(),v1.end());
        vector<vector<int>>ans;
        vector<vector<int>>op;
        vector<int>temp;
        solve (v1,ans,temp,0,0,target);
        return vector<vector<int>>(ans.begin(), ans.end());

    }
};


