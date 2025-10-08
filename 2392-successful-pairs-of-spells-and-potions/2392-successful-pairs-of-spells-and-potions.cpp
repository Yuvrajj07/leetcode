class Solution {
public:
    vector<int> successfulPairs(vector<int>& v1, vector<int>& v2, long long success) {
        vector<int>ans;
        sort(v2.begin(),v2.end());
        int n=v2.size();
        for (int i =0;i<v1.size();i++){
            long long req=success/v1[i];
            if (success%v1[i]!=0) req++;
            // cout<<req<<endl;
            int s=0,e=n-1,num=n;
            while (s<=e){
                int mid= (s+e)/2;
                if (v2[mid]>=req){
                    num=mid;
                    e=mid-1;
                }
                else if (v2[mid]>req){
                    e=mid-1;
                }
                else {
                    s=mid+1;
                }

            }
            cout<<num<<endl;
            ans.push_back(n-num);
        }
        return ans;
    }
};