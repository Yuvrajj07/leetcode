class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for (int i=0;i<logs.size();i++){
            string s=logs[i];
            if (s=="../"  ){
                if( ans>=1)
                ans--;
            }
            else if (s=="./"){
                ans=ans;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};