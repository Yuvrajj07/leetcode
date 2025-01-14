class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        unordered_set<int>s1;
        unordered_set<int>s2;
        
        int c=0;
        vector<int>ans;
        for (int i =0;i<a.size();i++){
            s1.insert(a[i]);
            s2.insert(b[i]);            
            vector<int> toErase;

            for (auto it :s1){
                int z=it;
                if (s2.find(z)!=s2.end()){
                    c++;
                    toErase.push_back(z);
                }
            }
            for (auto it:toErase){
                s1.erase(it);
                s2.erase(it);
                
            }

            ans.push_back(c);

        }
        return ans;
    }
};

