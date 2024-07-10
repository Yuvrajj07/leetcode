class Solution {
public:
    long long largestPerimeter(vector<int>& v) {
        sort(v.begin(),v.end());
        long long  sum=0,ans=-1;

        for (int i=0;i<v.size();i++){
            if (sum>v[i] && i>=2){
                ans=v[i]+sum;
                
            }
            sum+=v[i];
        }
        return ans;
        
    }
};