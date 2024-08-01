class Solution {
public:
    int numTeams(vector<int>& rating) {
     int ans=0,a=rating.size();
     for (int i =0;i<a-2;i++){
        for (int j =i+1;j<a-1;j++){
            for (int k=j+1;k<a;k++){
                if (rating[i]>rating[j] && rating[j]>rating[k]) ans++;
                 else if (rating[i]<rating[j] && rating[j] <rating[k]) ans++;   
            }
        }
     }   
     return ans;
    }
};