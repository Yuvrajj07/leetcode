/*

class Solution {
public:

// complexity --> O(N)

    int longestConsecutive(vector<int>&v) {
        if (v.size()==0) return 0;
        unordered_map<int ,int>m;
        for (int i =0;i<v.size();i++){
        m[v[i]]=1;
    }
    int mx= *max_element(v.begin(),v.end());
    int mn =*min_element(v.begin(),v.end());
    int ans =0,mx1=1;
    for (int i=mn;i<=mx;i++){
        auto it= i+1;
        if (m[it]==1){
            mx1++;
        }
        else {
       
            ans=max(ans,mx1);
                 mx1=0;
        }
        
    }
    ans=max(ans,mx1);
    return ans;
    }
};
*/

class Solution {
public:
    int longestConsecutive(std::vector<int>& v) {
        if (v.empty()) return 0;
        std::unordered_set<int> nums(v.begin(), v.end());
        int longest = 0;

        for (int num : nums) {
            if (nums.find(num - 1) == nums.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (nums.find(currentNum + 1) != nums.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longest = std::max(longest, currentStreak);
            }
        }

        return longest;
    }
};