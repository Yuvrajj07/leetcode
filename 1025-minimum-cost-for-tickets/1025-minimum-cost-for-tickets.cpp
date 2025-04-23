class Solution {
public:
    unordered_set<int>s;
    int solve(vector<int>&dp,vector<int>&days,vector<int>&costs,int i){
        if (i>days[days.size()-1]) return 0;
        if (s.find(i)==s.end()){
            return solve(dp,days,costs,i+1);
        }
        if (dp[i]!=-1) return dp[i];
        int oday=costs[0]+solve(dp,days,costs,i+1);
        int sday=costs[1]+solve(dp,days,costs,i+7);
        int thday=costs[2]+solve(dp,days,costs,i+30);
        return dp[i]=min(oday,min(sday,thday));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int m= costs.size();
        vector<int>dp(days[n-1]+1,-1);
        for (auto it :days){
            s.insert(it);
        }
        return solve(dp,days,costs,1);
    }
};