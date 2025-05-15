class Solution {
public:
    int findShortestSubArray(vector<int>& v) {
        unordered_map<int,int>m;
        int mx= -1;
        for (auto it:v){
            m[it]++;
            int num=m[it];
            mx=max(mx,num);
        }
        
        

        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for (int i =0;i<v.size();i++){

            if (m[v[i]]==mx && (m1.find(v[i])==m1.end())){
                m1[v[i]]=i;
            }
        }

        for (int i =v.size()-1;i>=0;i--){
            if (m[v[i]]==mx && (m2.find(v[i])==m2.end())){
                m2[v[i]]=i;
            }
        }
        
        int ans=v.size();
        for (auto it:m1){
            int pos1=it.second;
            int pos2=m2[it.first];
            ans =min (ans,abs(pos1-pos2)+1);

        }

        return ans;
    }
};