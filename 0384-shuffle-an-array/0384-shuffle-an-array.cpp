class Solution {
public:
    vector<int>temp={0};
    vector<int>v={0};
    int i =0,j=1;
    
    Solution(vector<int>& nums) {
        temp=nums;
        v=nums;
    }
    
    vector<int> reset() {
        v=temp;
        i=0,j=0;
        return v;
    }
    
    vector<int> shuffle() {
          int n = v.size();
        for (int i = 0; i < n; i++) {
            int j = rand() % (n - i) + i; // pick random index from [i, n-1]
            swap(v[i], v[j]);
        }
        return v;
        // int x=v.size();
        // if (x==1) return v;
        // if (j==x-1){
        //     i++;
        //     j=0;
        // }
        // swap(v[i],v[j]);
        // j++;
        // return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */