class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        const int MOD = 1e9 + 7;
        for (int i =0;i<n-1;i++){
            int sum=nums[i];
            for (int j=i+1;j<n;j++){
                // sum+=nums[j];
                  sum = (sum + nums[j]) % MOD;
                v.push_back(sum);
            }
        }
        for (int i =0;i<n;i++){
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end());
        long long op=0;
        for (int i =left-1;i<right;i++){
            // op+=v[i];
             op = (op + v[i]) % MOD;
        }
        return op;
    }
};