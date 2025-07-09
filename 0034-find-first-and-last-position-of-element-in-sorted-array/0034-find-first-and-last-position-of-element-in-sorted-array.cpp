class Solution {
public:
    int lastOcc(vector<int>&v,int target){
        int i =0,j=v.size()-1,mid,ans=-1;
        while (i<=j){
            mid= i+(j-i)/2;
            if (v[mid]==target){
                ans=mid;
                i=mid+1;
            }
            else if (v[mid]>target){
                j=mid-1;
            }
            else {
                i=mid+1;
            }
        }
        return ans;
    }
        int firstOcc(vector<int>&v,int target){
        int i =0,j=v.size()-1,mid,ans=-1;
        while (i<=j){
            mid= i+(j-i)/2;
            if (v[mid]==target){
                ans=mid;
                j=mid-1;
            }
            else if (v[mid]>target){
                j=mid-1;
            }
            else {
                i=mid+1;
            }
        }
        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);
        ans[0] = firstOcc(nums,target);
        ans[1] = lastOcc(nums,target);

        return ans;
    }
    
};