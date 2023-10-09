class Solution {
public:
    int firstOcc(vector<int>&v,int target){
        int sum=-1;
        for (int i=0;i<v.size();i++){
            if(v[i]==target) {
                sum=i;
                break;
            } 
        }
        return sum;
    }

int num=-1;
    int lastOcc(vector<int>&v, int target){
         for (int i=v.size()-1;i>=0;i--){
            if(v[i]==target) {
                num=i;;
                break;
            } 
        }
        return num;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);
        ans[0] = firstOcc(nums,target);
        ans[1] = lastOcc(nums,target);

        return ans;
    }
    
};
