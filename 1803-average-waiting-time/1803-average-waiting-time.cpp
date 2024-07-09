class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& v) {
        int ideatime =0;
        double  wt=0;
        for (int i =0;i<v.size();i++){
            // if(total>v[i][1]){
            //     total=total-v[i][1];

            // }
            // else {
            //     total=total+
            // }
            ideatime=max(v[i][0],ideatime)+v[i][1];
            wt= wt+(ideatime-v[i][0]);
        }
return wt/v.size();
        
    }
};