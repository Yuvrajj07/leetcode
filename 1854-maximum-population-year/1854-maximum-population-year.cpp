class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
     int ans=0,mx=0;
        map<int,int>m;
       for ( auto log : logs) {
            m[log[0]]++;
            m[log[1]]--; 
        }
        int print=0;
        for (auto it :m){
            ans+=it.second;
            if (ans>mx){
                print=it.first;
                mx=ans;
            }
            
        }
        return print;
    }
};
        
//       