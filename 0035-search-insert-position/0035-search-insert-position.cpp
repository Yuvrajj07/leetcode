class Solution {
public:
    int searchInsert(vector<int>&v, int target) {
        int n=v.size();
        int s=0;
        int e=n-1;
        int ans=n;

        while(s<=e){
            int mid=s+(e-s)/2;

            if(v[mid]==target){
                return mid;

            }
            else if(v[mid]>target){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};