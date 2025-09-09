// class Solution {
// public:
//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         queue<pair<int,int>>q;
//         q.push({1,delay});
//         n--;
//         while (n--){
//             queue<pair<int,int>>d;
//             while (!q.empty()){
//                 int x= q.front().first;
//                 int y= q.front().second;
//                 y--;
//                 q.pop();
//                 if (y==delay-forget){
//                     continue;
//                 }
//                 if (y<=0){
//                     d.push({x+1,delay});
                    
//                 }
//                 d.push({x,y});
                    
//             }
//             q=d;
//         }
//         return q.size();
//     }
// };


class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        
        long long share = 0;
        
        for (int day = 2; day <= n; ++day) {
            // People start sharing after 'delay' days
            if (day - delay >= 1) {
                share = (share + dp[day - delay]) % MOD;
            }
            // People forget after 'forget' days
            if (day - forget >= 1) {
                share = (share - dp[day - forget] + MOD) % MOD;
            }
            
            dp[day] = share;
        }
        
        long long result = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            if (day >= 1)
                result = (result + dp[day]) % MOD;
        }
        
        return result;
    }
};
