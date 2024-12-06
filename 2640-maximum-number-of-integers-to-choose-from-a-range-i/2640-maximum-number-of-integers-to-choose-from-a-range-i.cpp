class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
       int ans =0;
       int i =0;
       unordered_set<int>s;
    for (auto it:banned){
        s.insert(it);
    }
    for (int i=1;i<=n;i++){
        if (s.find(i)==s.end()){
            if (maxSum-i>=0)
            ans++;
            maxSum-=i;

        }
    }
    return ans;
    }
};