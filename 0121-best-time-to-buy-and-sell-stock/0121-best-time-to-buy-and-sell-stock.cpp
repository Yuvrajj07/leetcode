class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        stack <int>st;
        for (int i =0;i<nums.size();i++){
            st.push(nums[i]);
        }
        vector<int>v1(n,0);
        int p=n-1,mx=-1;
        while(!st.empty()){
            int tp= st.top();
            int diff=(mx-tp);
            mx=max(mx,tp);
            v1[p]=diff;
            p--;
            st.pop();
        }
        int ans=0;
        for(auto it :v1){
            ans=max(ans,it);
        }
        return ans;

    }
};