class Solution {
public:
    int numberOfPairs(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[1] == b[1]) 
            return a[0] < b[0]; // when second is same → sort first descending
        return a[1] > b[1];     // otherwise → sort second ascending
    });
        for (auto it:v){
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        int ans=0;
        for (int i =0;i<v.size();i++){
            int x1=v[i][0],y1=v[i][1];
            int minx=INT_MAX;
            for (int j=i+1;j<v.size();j++){
                int x2=v[j][0],y2=v[j][1];
                
                if (y1>=y2 && x2>=x1 ) {
                   if (x2 < minx) {
                        ans++;
                        minx = x2; // update blocker
                    }
                  }


                }
            }

        
        return ans;
    }
};