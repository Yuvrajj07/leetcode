class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        
        // First, add elements smaller than pivot
        for (int num : nums) {
            if (num < pivot) ans.push_back(num);
        }
        
        // Then, add elements equal to pivot
        for (int num : nums) {
            if (num == pivot) ans.push_back(num);
        }
        
        // Finally, add elements greater than pivot
        for (int num : nums) {
            if (num > pivot) ans.push_back(num);
        }
        
        return ans;
    }
};
