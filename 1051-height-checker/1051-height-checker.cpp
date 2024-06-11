class Solution {
public:
    int heightChecker(vector<int>& heights) {
        multiset<int>m;
        for (int i=0;i<heights.size();i++){
            m.insert(heights[i]);
        }
        int ans =0;
        for (int i =0;i<heights.size();i++){
            if (heights[i]!=*m.begin()) {
                ans++;
            }
            m.erase(m.begin());
        }
        return ans;
    }
};