// class Solution {
// public:
//     int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
//         int t=tops[0],b=bottoms[0];
//         int t1=0,t2=0,b1=0,b2=0;
//         for (int i=0;i<tops.size();i++){
//             if(tops[i]!=t){
//                 if(bottoms[i]==t) t1++; 
//             }
//             else t2++;

//             if (bottoms[i]!=b){
//                 if (tops[i]==b) b1++;
//             }
//             else b2++;
//         }
//         int ans=-1;
//         if (t1+t2==tops.size()){
//             ans=t1;
//         }
//         if (b1+b2==tops.size()){
//             if (ans!=-1) ans=min(ans,b1);
//             else ans= b1;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int a = tops[0], b = bottoms[0];

        auto check = [&](int target) -> int {
            int rotate_top = 0, rotate_bottom = 0;
            for (int i = 0; i < n; i++) {
                if (tops[i] != target && bottoms[i] != target)
                    return -1; // impossible
                if (tops[i] != target) rotate_top++;
                if (bottoms[i] != target) rotate_bottom++;
            }
            return min(rotate_top, rotate_bottom);
        };

        int res1 = check(a);
        int res2 = (a == b) ? res1 : check(b);

        if (res1 == -1) return res2;
        if (res2 == -1) return res1;
        return min(res1, res2);
    }
};
