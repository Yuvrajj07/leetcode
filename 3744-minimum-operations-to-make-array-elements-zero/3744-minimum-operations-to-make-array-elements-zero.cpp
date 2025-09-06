class Solution {
public:
    int solve(long long num) {
    if (num == 0) return 0;
    int msb = __lg(num);        
    return (msb + 2) / 2;        
}
    long long minOperations(vector<vector<int>>& v) {
        long long ans = 0;
        for (auto it :v){
            long long  start =it[0],end=it[1];
            long long  csum=0;
           
        while (start <= end) {
            int msb = __lg(start);
            long long blockEnd = min(end, (1LL << (msb+1))-1);

            long long count = blockEnd - start + 1;
            int steps = solve(start); // same for whole block

            csum += count * steps;
            start = blockEnd + 1;
        }
            ans+=(csum+1)/2;
        }
        return ans;
    }
};