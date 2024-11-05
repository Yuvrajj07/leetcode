class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        int i =0,j=v.size()-1,ans=0;
        sort (v.begin(),v.end());
        while (i<=j){
            if (v[i]+v[j]<=limit){
                i++;
                j--;
                ans++;
            }
            else {
                ans++;
                j--;
            }
        }
        return ans;
    }
};