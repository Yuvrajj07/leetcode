class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int ans=0,prev=0,curr=0;
        for (int i =0;i<v.size();i++){
            if (v[i]==0){
                ans=max(ans,prev+curr);
                prev=curr;
                curr=0;
            }
            else {
                curr++;
            }
        }
        ans=max(ans,prev+curr);
        return  (ans==v.size()) ?ans-1:ans;

        
    }
};