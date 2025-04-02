// class Solution {
// public:
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         vector<pair<int,int>> p;
//         for (int i = 0; i < mat.size(); i++) {
//             int sum = 0;
//             for (int j = 0; j < mat[i].size(); j++) {
//                 sum += mat[i][j];
//             }
//             p.push_back({sum, i});
//         }
//         sort(p.begin(), p.end());
        
        
//     // printing the vector of pairs 
        
//         // for (auto it :p){
//         //     cout<< it.first<<" "<<it.second<<endl;
//         // }
//         vector<int> result;
//         for (int i = 0; i < k; i++) {
//             result.push_back(p[i].second);
//         }
//         return result;
//     }
// };

// binary search -->         O(log(n))
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> p;
        for (int i = 0; i < mat.size(); i++) {
            int sum = 0;
            int s = 0, e = mat[i].size() - 1;
            while (s <= e) {
                int m = (s + e) / 2;
                if (mat[i][m] == 1) {
                    sum += m - s + 1; // Increment sum by the count of 1s in this segment
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            }
            p.push_back({sum, i});
        }
        sort(p.begin(), p.end()); 
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(p[i].second);
        }
        return result;
    }
};








