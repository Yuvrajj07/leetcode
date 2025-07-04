class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n+1))/2;
        int sumar = 0;
        for(int i=0;i<nums.size(); i++)
            sumar += nums[i];
        return sum-sumar;
    }
};