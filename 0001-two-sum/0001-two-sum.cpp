class Solution {
public:
       vector<int> twoSum(vector<int> &nums, int target){
           unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int com = target - nums[i];
            if (m.find(com) != m.end())
            {
                return {m[com], i};
            }
            //cout<<m[com]<<endl;
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};