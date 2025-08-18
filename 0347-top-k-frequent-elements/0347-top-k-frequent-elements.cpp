class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        for (auto it:nums){
            m[it]++;
        }
        int n=nums.size();
        vector<vector<int>>bucket(n+1);
        vector<int>ans;
        // vector<vector<int>> bucket(n + 1); 
        for (auto &p : m) {
            bucket[p.second].push_back(p.first);
        }
        
        for (int i = n; i >= 1 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) return ans;
            }
        }
        return ans;
    }
};