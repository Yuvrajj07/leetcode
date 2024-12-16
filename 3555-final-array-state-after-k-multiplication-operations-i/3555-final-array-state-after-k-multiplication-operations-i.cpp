class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     int i=0;
     for(int &a:nums)
     {
        pq.push({a,i++});
     }   
     while(k--)
     {
        pair<int,int>p=pq.top();
        pq.pop();
        int a=p.first;
        int b=p.second;
        pq.push({a*multiplier,b});
        nums[b]*=multiplier;
     }
     return nums;
    }
};