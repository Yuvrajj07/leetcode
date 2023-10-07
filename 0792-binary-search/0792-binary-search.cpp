class Solution {
public:
    int search(vector<int>&v, int target) {
        int s=0,n=v.size(),e=n-1,ans;
        while (s<=e){
            int mid = s+(e-s)/2;
            if (v[mid]==target){
                return mid;
            }
            else if (v[mid]>target ){
                e= mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return -1;
    }
};