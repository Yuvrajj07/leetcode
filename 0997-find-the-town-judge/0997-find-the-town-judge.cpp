class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size()==0  ){
            if (n==1) return 1;
            else return -1;
        }
        vector<int>v(1001,0);
        unordered_map<int,int>mp;
        unordered_set<int>st;
        for (int i =0;i<trust.size();i++){
            int num1= trust[i][0];
            int num2= trust[i][1];
            mp[num2]++;
            st.insert(num1);
            v[num1]=1;
            v[num2]=1;
        }      
        for (auto it :mp) cout<<it.first<<" "<<it.second<<endl;
        for (int i=1;i<=1000;i++){
            if (v[i]==1){
                if ( mp[i]==n-1 && st.find(i)==st.end()) return i;
            }
        }

        return -1;
    }
};