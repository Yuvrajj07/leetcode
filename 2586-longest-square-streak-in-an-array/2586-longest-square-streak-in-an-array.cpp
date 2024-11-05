class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<long long,long long>m;
        for (int i =0;i<nums.size();i++){
            long long x=nums[i];
            m[x*x]=1;
        }
        int mx=0,ans=0;
        for (int i =0;i<nums.size();i++){
            long long z=nums[i];
            long long f=z*z;
             while (m.find(f)!=m.end()){
                ans++; 
                if (f<=100000) {
                    f=f*f;
                } 
                else {
                    
                    break;
                }
            }
            mx = max(mx,ans);
        ans=0;
            // while (true){
            //     if (m.find(f)!=m.end()){
            //         ans++;
            //         if (f*f<=100000){
            //             f=f*f;
            //         }
            //     }
            //     else {
            //         mx=max(ans,mx);
            //         ans=0;
            //         break;
            //     }
                
            }
        
        for (auto it :m){
            cout<<it.first <<" "<<it.second<<endl;
        }
        cout<<endl;
        if (mx==1) return -1;
        return mx;
    }
};