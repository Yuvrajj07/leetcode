class Solution {
public:
    int maxSubarrayLength(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int i=0,j=0,n=arr.size();
        int maxi=INT_MIN,ans=INT_MIN;
        while(j<n){
            mp[arr[j]]++;

            maxi=max(maxi,mp[arr[j]]);

            if(maxi<=k) {
                ans=max(ans,j-i+1);
                j++;
            }

            else{
                while(mp[arr[j]]>k && i<=j){
                    mp[arr[i]]--;
                    i++;
                }
                maxi=mp[arr[j]];
                j++;
            }
        }
        return ans;
    }
};

//                      '''''''''''''''''''''''...............................'''''''''''''''''''''''
// class Solution {
// public:
//     int maxSubarrayLength(vector<int>&v, int k) {
//         int right =0,left=0,ans=0;
//         unordered_map<int ,int >m;
//         while (right <v.size()){
//             bool chk =true;
//             m[v[right]]=m[v[right]]+1;
//             for (auto it:m){
//                 if(it.second==k+1){
//                     chk=false;
//                 }
//             }
//             if (chk){
//                 int x=right-left+1;
//                 right++;
//                   if (x>ans) ans=x;
                
//             }
//             else {
//                 m[v[left]]=m[v[left]]-1;
//                 left++;
               
//             }
//         }
//         return ans;
//     }
// }; 