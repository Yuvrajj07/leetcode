class Solution {
public:
vector<int>dp;
  int solve(int i, vector<int>& v) {
        if (i <= 0) return 0; // base case
        if (dp[i] != -1) return dp[i]; 
        return dp[i] = max(v[i] + solve(i-2, v), solve(i-1, v));
    }

    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>m;
        for (auto it:nums){
            m[it]++;
        }
        vector<int>v(20001,0);
        for (int i =1;i<=20000;i++){
            v[i]=i*m[i];
        }
        
        dp.assign(20001, -1);
        return solve(20000, v);
    }
};


// calculate the sum of every element and store it in an array . and find the max  sum of entire array by not taking the consecutive elements  