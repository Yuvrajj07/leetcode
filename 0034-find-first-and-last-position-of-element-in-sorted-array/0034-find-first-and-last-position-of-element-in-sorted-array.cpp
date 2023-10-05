class Solution {
public:
    int firstOcc(vector<int>&nums,int target){
        int s=0,ans=-1;
        int e=nums.size()-1;
        int  mid=s+(e-s)/2;

        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

            mid = s+(e-s)/2;
        }

        return ans;
    }

    int lastOcc(vector<int>&nums, int target){
        int s=0,ans=-1;
        int e=nums.size()-1;
        int  mid=s+(e-s)/2;

        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

            mid = s+(e-s)/2;
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);
        ans[0] = firstOcc(nums,target);
        ans[1] = lastOcc(nums,target);

        // ans.push_back(first);
        // ans.push_back(second);

        return ans;
    }
};