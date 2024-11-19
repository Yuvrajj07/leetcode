class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) {
           unordered_map<int,int>m;
           long long   i =0,j=0,sum =0,ans=0;
           while (j<v.size()){
                m[v[j]]++;
                sum+=v[j];

            if (j-i+1==k){
                if (m.size()==k){
                    ans=max(ans,sum);
                }
                sum-=v[i];
                m[v[i]]--;
                if (m[v[i]] == 0) {
                    m.erase(v[i]);
                }
                i++;
            }
                j++;

           }
           return ans;
    }
};