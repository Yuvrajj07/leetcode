class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        for (int i =0;i<v.size();i++){
            v[i]=pow(v[i],2);
        }
        sort(v.begin(),v.end());
        return v;
    }
};