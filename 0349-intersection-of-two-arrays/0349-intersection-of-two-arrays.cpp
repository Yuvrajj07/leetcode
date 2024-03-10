class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(1001,0);
        for (int i =0;i<nums1.size();i++){
                int x= nums1[i];
                ans[x]=1;
        }
        for (int i =0;i<nums2.size();i++){
                int x= nums2[i];
                if (ans[x]!=0)
                ans[x]=2;
                
        }
        
        vector<int>r;
        for (int i =0;i<ans.size();i++){
            if (ans[i]==2) {
                r.push_back(i);
            }
        }
                // for (int i =0;i<ans.size();i++){
                // cout<<ans[i]<<" ";
                // }
        

        return r;
    }
};