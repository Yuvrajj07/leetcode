class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int size= nums.size();
        
        int mx= *max_element(nums.begin(),nums.end());
        vector<int>differences(mx+1,0); // created a vector of possible diffenences which can occur 
        for (int i =0;i<size;i++){
            for (int j=i+1;j<size;j++){
                int diff=abs(nums[i]-nums[j]);  // finding all the posssible difference 
                differences[diff]++;              // counting the number of occurence of a difference_number
            }
        }
        for (int i =0;i<mx+1;i++){
            k=k-differences[i];
            if (k<=0) return i;
        }
        return -1;
    }
};

