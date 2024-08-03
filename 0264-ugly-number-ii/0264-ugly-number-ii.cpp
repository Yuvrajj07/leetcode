struct Solution {
    int nthUglyNumber(int n) {
        vector <int> results (1,1);
        int i = 0, j = 0, k = 0;
        while (results.size() < n)
        {
            results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
            if (results.back() == results[i] * 2) ++i;
            if (results.back() == results[j] * 3) ++j;
            if (results.back() == results[k] * 5) ++k;
        }
        return results.back();
    }
};

//               ....................BRUTE_FORCE....................

// class Solution {
// public:
// bool ugly(int n){
//     while (n>0){
//         if (n==1) return true;
//         if (n%2!=0 && n%3!=0  && n%5!=0){
//             return false;
//         }
//         if (n%2==0) n=n/2;
//         else if (n%3==0) n=n/3;
//         else n=n/5;
//     }
//     return true;
// }
//     int nthUglyNumber(int- n) {
//         int ans ,i=1,cnt=0;
//         while(cnt<n){
//             if (ugly(i)){
//                 ans=i;
//                 cnt++;
//             }
//             i++;
//         }
//         return ans;
//     }
// };