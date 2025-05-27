class Solution {
public:        
    int ans=0;
    int differenceOfSums(int n, int m) {
        for (int i =1;i<=n;i++) (i%m!=0)? ans+=i: ans-=i;
        return ans;
    }
};