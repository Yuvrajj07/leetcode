class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0,start=0;
         int currentSum=0;
        for (int i =0;i<s.length();i++){
           
            currentSum +=abs(s[i]-t[i]);
            while (currentSum>maxCost){
                currentSum -= abs(s[start]-t[start]);
                start++;
            }
            cout<<currentSum<<endl;
            ans = max(ans, i - start + 1);
        }
            
        return ans;
    }
};   