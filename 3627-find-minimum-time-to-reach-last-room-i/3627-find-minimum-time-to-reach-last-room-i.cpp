#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        using State = pair<int, pair<int, int>>; // {time, {x, y}}
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, {0, 0}});
        time[0][0] = 0;

        while (!pq.empty()) {
            auto [currTime, pos] = pq.top(); pq.pop();
            auto [x, y] = pos;

            if (visited[x][y]) continue;
            visited[x][y] = true;

            for (auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int nextTime = max(currTime, grid[nx][ny]) + 1;
                if (nextTime < time[nx][ny]) {
                    time[nx][ny] = nextTime;
                    pq.push({nextTime, {nx, ny}});
                }
            }
        }

        return time[n-1][m-1];
    }
};






// class State {
// public:
//     int x;
//     int y;
//     int dis;
//     State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
// };

// class Solution {
// public: 
//     int minTimeToReach(vector<vector<int>>& v1){
//         int inf=0x3f3f3f3f;
//         int n=v1.size(),m=v1[0].size();
//         vector<vector<int>>d(n,vector<int>(m,inf));
//         vector<vector<int>>v(n,vector<int>(m,0));
//         int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
//         d[0][0]=0;
//         auto cmp =[](const State& a,State& b) {return a.dis>b.dis;};
//           priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
//         q.push(State(0, 0, 0));
//         while (!q.empty()){
//             State s=q.top();
//             q.pop();
//             if(v[s.x][s.y]) continue;
//             v[s.x][s.y]=1;
//               for (int i = 0; i < 4; i++) {
//                 int nx = s.x + dirs[i][0];
//                 int ny = s.y + dirs[i][1];
//                 if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

//                 int dist = max(d[s.x][s.y],v1[nx][ny]) + 1;
//                 if (d[nx][ny] > dist) {
//                     d[nx][ny] = dist;
//                     q.push(State(nx, ny, dist));
//                 }
//             }
//         }
//         return d[n-1][m-1];
                
//     }
// };