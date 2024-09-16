class Solution {
public:
    int findMinDifference(vector<string>& v) {
        
        vector<int>v1;
        for (auto it:v){
            int hours = stoi(it.substr(0, 2));
            int mins = stoi(it.substr(3, 2));
            int z= (hours*60)+mins;
            v1.push_back(z);
        }
        sort(v1.begin(),v1.end());
        for (auto it :v1){
            cout<<it<<" ";
        }

        int ans =INT_MAX;
        for (int i =0;i<v1.size()-1;i++){
            int mx = abs(v1[i]-v1[i+1]);
            ans =min(ans,mx);
        }
        int c1=1440-v1[v1.size()-1]+v1[0];
        cout<<endl;
        cout<<c1<<endl;
        ans =min(c1,ans);
        return ans;
    }
};