class Solution {
public:
    int findPeakElement(vector<int>&s) {
     int z= max_element(s.begin(),s.end())-s.begin();
    return z;
    }
};