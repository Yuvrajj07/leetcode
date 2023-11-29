class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        set<int>s;
        for(int i:nums)
        {
            s.insert(i);
        }
        for(auto it:s)
        {
            nums[cnt]=it;
            cnt++;
        }
        return cnt;
    }
};