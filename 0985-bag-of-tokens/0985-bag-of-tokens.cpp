class Solution {
public:
    int bagOfTokensScore(vector<int>& V, int pow) {
        sort(V.begin(),V.end());
        int ans=0,res=0,i=0,j=V.size()-1;
        while(i<=j){
            if(pow>=V[i]){
                pow-=V[i++];
                res=max(res,++ans);
            }else if(ans>0){
                ans--;
                pow+=V[j--];
            }else{ break; }
        }
        return res;
    }

};