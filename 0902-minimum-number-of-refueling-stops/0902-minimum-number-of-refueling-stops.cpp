class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        multiset<int, std::greater<int>>m;
        int ans=0;
        int curr=startFuel;
        sort(stations.begin(),stations.end());
        for (auto it:stations){
            int station =it[0];
            int fuel=it[1];
            while  (curr<station){
                if (m.empty()){
                    return -1;
                }
                else {
                    curr+=*m.begin();
                    ans++;
                    m.erase(m.begin());
                }
            }
                m.insert(fuel);
        }
        while (curr<target){
            if (m.empty()){
                    return -1;
                }
                else {
                    curr+=*m.begin();
                    ans++;
                    m.erase(m.begin());
                }
        }
              
              return ans;
    }
};
