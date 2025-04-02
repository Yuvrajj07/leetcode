class Solution {
public:
    int singleNumber(vector<int>& nums) {
       unordered_map<int,int>m;
        for (int i =0;i<nums.size();i++){
          m[nums[i]]= m[nums[i]]+1;
        }
        int x;
        unordered_map<int,int> :: iterator it;
        for (it=m.begin();it!=m.end();it++){
            if ((*it).second==1){
            x= (*it).first;
            }
        }
      return x;
    }
};