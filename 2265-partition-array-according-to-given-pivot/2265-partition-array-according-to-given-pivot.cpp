// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         int pos=-1;
//         for (int i =0;i<nums.size();i++){
//             if (nums[i]==pivot){
//                 pos=i;
//                 break;
//             } 
//         }
//         vector<int>ans(nums.size());
//         ans[pos]=pivot;
//         int i =0,j=pos+1;
//         for (int i =0;i<nums.size();i++){
//             if (nums[i]<pivot){
//                 ans[i]=nums[i];
//                 i++;
//             }
//             else {
//                 ans[j]=nums[i];
//                 j++;
//             }
//         }
//         return ans;
//     }
// };


/*
    ...................................approach : take three vectors........................
    
    1)- left vector :for samller values
    2)- mid vector :for equal  values
    3)- right vector :for larger values
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, right, mid;
        
        for (int num : nums) {
            if (num < pivot) left.push_back(num);
            else if (num > pivot) right.push_back(num);
            else mid.push_back(num);
        }
        
        vector<int> ans;
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), mid.begin(), mid.end());
        ans.insert(ans.end(), right.begin(), right.end());
        
        return ans;
    }
};
