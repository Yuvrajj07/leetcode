class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n= g.size();
        vector<bool>vis(n,false);
        vector<vector<int>>ans;
        queue<vector<int>> q;
        q.push({0});
        while (!q.empty()){
            vector<int>v1= q.front();
            q.pop();
            // v1.push_back(x);
            // q.pop();

            int lt=v1.back();
            if (lt==n-1){
                ans.push_back(v1);
            }
            else {
                for (auto it :g[lt]){
                    vector<int>np=v1;
                    np.push_back(it);
                    q.push(np);
                }
            }
        }
        return ans;
        
    }

};