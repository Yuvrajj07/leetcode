

/*



                                ..............................BRUTE FORCE ...........!!!!!!!!!!!!!!!!!!!!!!!!


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& v) {
        vector<pair<int,pair<int,int>>>v1;
        for (int i =0;i<v.size();i++){
            v1.push_back({v[i][1],{v[i][0],v[i][2]}});
        }
        sort(v1.begin(),v1.end());
        int ans=0;
        int mx=0;
        for (int i=v1.size()-1;i>=0;i--){
                mx=max(mx,v1[i].second.second);
            for (int j=i-1;j>=0;j--){
                    if(v1[i].second.first>v1[j].first){
                       ans=max(ans,v1[j].second.second+v1[i].second.second);
                    }
            }
            ans=max(mx,ans);
        }
        return ans;
    }
};
*/


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& v) {
        // Sort events by their end times
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        
        int n = v.size();
        vector<int> v1(n, 0);
        
        // Step 1: Create a prefix max array `v1`
        v1[0] = v[0][2]; // Initialize with the value of the first event
        for (int i = 1; i < n; i++) {
            v1[i] = max(v1[i - 1], v[i][2]);
        }
        
        int result = 0;

        // Step 2: Iterate through events and calculate the maximum value for two non-overlapping events
        for (int i = 0; i < n; i++) {
            int currValue = v[i][2];
            
            // Use binary search to find the best non-overlapping event
            int low = 0, high = i - 1, bestValue = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (v[mid][1] < v[i][0]) { // Non-overlapping condition
                    bestValue = max(bestValue, v1[mid]);
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            // Update the result
            result = max(result, currValue + bestValue);
        }
        
        return result;
    }
};



// class Solution {
// public:
//     int maxTwoEvents(vector<vector<int>>& v){
//         sort(v.begin(),v.end(),[](const vector<int> &a,const vector<int> &b) { return a[1]<b[1];});
//         int n=v.size();
//         vector<int>v1(n,0);
//         v1[0]=v[0][2]; 
//         for (int i =1;i<n;i++){
//            v1[i]=(v1[i - 1],v[i][2]); 
//         }     

//          int result = 0;
//         for (int i = 0; i < n; i++) {
//             int currValue = v[i][2];
//             int low = 0, high = i - 1, bestValue = 0;
//             while (low <= high) {
//                 int mid = low + (high - low) / 2;
//                 if (v[mid][1] < v[i][0]) { // Non-overlapping
//                     bestValue = max(bestValue, v1[mid]);
//                     low = mid + 1;
//                 } else {
//                     high = mid - 1;
//                 }
//             }
//             result = max(result, currValue + bestValue);
//         }

//         return result;
//     }
// };
