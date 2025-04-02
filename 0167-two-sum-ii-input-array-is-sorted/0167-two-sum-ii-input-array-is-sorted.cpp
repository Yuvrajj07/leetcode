class Solution {
public:
    vector<int> twoSum(vector<int>&v, int target) {
        int x = v.size();
        int i=0,j=x-1;
        vector<int>ans;
        while (i<j){
            if (v[i]+v[j]==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                i++;
                j--;
            }
            else if (v[i]+v[j]>target){
                j--;
            }
            else {
                i++;
            }
        }
        return ans;
    }
};