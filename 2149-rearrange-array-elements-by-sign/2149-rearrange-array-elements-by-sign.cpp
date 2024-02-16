class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;
        for (int i=0;i<nums.size();i++){
            if(nums[i]>0) pos.push_back(nums[i]);
            else  neg.push_back(nums[i]);
        }
        int i=0,j=0;
        int x=nums.size();
        while(i<x/2){
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }
        return ans;
    }
};

// effective  solution : less space 

// we will take two pointers initially at 0 and one bool=true chk
// we will use one counter for positive value and other for negative values
// push the value of positive
// increase the counter --> i++; 
// do bool = false
// when bool is false we will insert the next negative value 
// increse the counter --> j++;
// do bool=true 
