class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int ans=arr[0],mxans=arr[0];
        for(int  i =1;i<arr.size();i++){
            mxans=max(arr[i],mxans+arr[i]);
            ans= max(ans,mxans);
        } 
        return ans;
    }
};