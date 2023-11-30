class Solution {
public:
    int removeElement(vector<int>& v, int val) {
       int sum =0;
       for (int i =0;i<v.size();i++){
           if (v[i]==val){
               v[i]=INT_MAX;        // removing occurances of val
           }
           else {
               sum++;
           }
       }
       // sort the vector so the values which we changed  will be shifted to the left most side
       sort(v.begin(),v.end());
       return sum ;
    }
};