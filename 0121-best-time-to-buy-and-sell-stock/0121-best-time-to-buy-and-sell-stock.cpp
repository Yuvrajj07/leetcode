class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size()-1;
        int largest=prices[n];
        int ans =0;
        for (int i=n-1;i>=0;i--){
            int diff=largest-prices[i];
            ans=max(diff,ans);
            largest=max(largest,prices[i]);
        }
        return ans;

    }
};