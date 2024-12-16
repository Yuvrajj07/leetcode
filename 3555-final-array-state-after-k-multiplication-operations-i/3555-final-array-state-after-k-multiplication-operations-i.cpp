class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
     multiset<pair<int,int>>m;
     for (int i =0;i<nums.size();i++){
        m.insert({nums[i],i});
     }
     while (k--){
        pair<int,int>p1=*m.begin();
        int x= p1.first;
        int y= p1.second;
        m.erase(m.begin());
        nums[y]=x*multiplier;
        m.insert({nums[y],y});
     }
     return nums;
    }
};

// class Solution {
// public:
//     vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
//      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//      int i=0;
//      for(int &a:nums)
//      {
//         pq.push({a,i++});
//      }   
//      while(k--)
//      {
//         pair<int,int>p=pq.top();
//         pq.pop();
//         int a=p.first;
//         int b=p.second;
//         pq.push({a*multiplier,b});
//         nums[b]*=multiplier;
//      }
//      return nums;
//     }
// };