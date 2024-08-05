class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string ,int>m;
        for (int i =0;i<arr.size();i++){
            m[arr[i]]++;
        }
        int c=0;
        string ans="";
        for (int i=0;i<arr.size();i++){
            if (m[arr[i]]==1){
                c++;
                if (c==k) ans=arr[i];
            }
        }
        return ans;
        
    }
};