class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans =0;
        int t1=special[0]-bottom;
        int t2=top- special[special.size()-1];
        for (int i =0;i<special.size()-1;i++){
            if (special[i+1]!=special[i]+1){
                ans =max(ans, (special[i+1]-special[i]-1));

            }
        }
        ans =max(ans,max(t1,t2));
        return ans;
        

    }
};