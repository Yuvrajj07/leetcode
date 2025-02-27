class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int>s;
        for (auto it:arr){
            s.insert(it);
        }
        int ans =0;
        for (int i =0;i<arr.size();i++){
             for (int j=i+1;j<arr.size();j++){
                int prev=arr[i],curr=arr[j];
                int z= prev+curr;
                int cnt=2;
                while (s.find(z)!=s.end()){
                        cnt++;
                        ans=max(ans,cnt);
                        prev=curr;
                        curr=z;
                         z=prev+curr;
                }
             }
        }
        return ans;
        
    }
};