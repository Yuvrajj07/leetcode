// class Solution {
// public:
//     int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
//         multiset<int,std::greater<int>>m1;
//         multiset<int,std::greater<int>>m2;
//         for (auto it :tasks){
//             m1.insert(it);
//         }
//         for (auto it :workers){
//             m2.insert(it);
//         }
//         int ans=0;
//         while (!m1.empty()){
//             if(*m2.begin()>=*m1.begin()){
//                 ans++;
//                 m1.erase(m1.begin());
//                 m2.erase(m2.begin());
//             }
//             else if(*m2.begin()<*m1.begin()){
//                 if (pills>0){
//                     int x= *m2.begin();
//                     if (x+strength>=*m1.begin()){
//                         ans++;
//                         pills--;
//                         m1.erase(m1.begin());
//                         m2.erase(m2.begin());
//                     }
//                     else {
                        
//                         m1.erase(m1.begin());
//                     }
//                 }
//                 else   m1.erase(m1.begin());
//             }
//         }
//         return ans;        
//     }
// };


class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int mid) -> bool {
            int p = pills;
            deque<int> ws;
            int ptr = m - 1;
            // Enumerate each task from largest to smallest
            for (int i = mid - 1; i >= 0; --i) {
                while (ptr >= m - mid && workers[ptr] + strength >= tasks[i]) {
                    ws.push_front(workers[ptr]);
                    --ptr;
                }
                if (ws.empty()) {
                    return false;
                }
                // If the largest element in the deque is greater than or equal
                // to tasks[i]
                else if (ws.back() >= tasks[i]) {
                    ws.pop_back();
                } else {
                    if (!p) {
                        return false;
                    }
                    --p;
                    ws.pop_front();
                }
            }
            return true;
        };

        int left = 1, right = min(m, n), ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};