class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> left;   // acts like max-heap (stores smaller half)
        multiset<int> right;  // acts like min-heap (stores larger half)

        // Combine both arrays into one
        vector<int> merged;
        merged.reserve(nums1.size() + nums2.size());
        merged.insert(merged.end(), nums1.begin(), nums1.end());
        merged.insert(merged.end(), nums2.begin(), nums2.end());

        // Insert elements one by one maintaining heap balance
        for (int num : merged) {
            right.insert(num);                         // Step 1: insert into min-heap
            left.insert(*right.begin());               // Step 2: move smallest from right to left
            right.erase(right.begin());                // remove from right

            // Step 3: if left is larger, move max from left to right
            if (left.size() > right.size()) {
                right.insert(*prev(left.end()));
                left.erase(prev(left.end()));
            }
        }

        // Calculate and return median
        int totalSize = merged.size();
        if (totalSize % 2 == 0) {
            return (*left.rbegin() + *right.begin()) / 2.0;
        } else {
            return *right.begin();
        }
    }
};
